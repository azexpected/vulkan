#pragma once
#ifndef RESOURCE_H
#define RESOURCE_H

#include "GuidRtti.h"
#include <unordered_map>
#include "../External/boost_1_65_1/boost/functional/hash/hash.hpp"
#include "../External/boost_1_65_1/boost/uuid/uuid.hpp"

template<typename T>
using uuid_unordered_map = std::unordered_map<boost::uuids::uuid, T, boost::hash<boost::uuids::uuid>>;

class Eombject : public GuidRtti
{
public:	
	using EombjectWp = std::weak_ptr<Eombject>;
	using EombjectSp = std::shared_ptr<Eombject>;

	template<typename ChildType, typename Constructor, typename ... ConstructorParams>
	static bool New(std::shared_ptr<ChildType>& spOut, const Constructor& constructor, const std::string& filePath, const ConstructorParams& ... args)
	{
		if (Find(spOut, filePath))
			return false;

		spOut = std::shared_ptr<ChildType>(constructor(args...), [](ChildType* p)
		{
			if (p)
			{
				auto namedResource = s_filePathTable.find(p->GetFilePath());
				if (namedResource != s_filePathTable.end())
					s_filePathTable.erase(namedResource);
			
				auto obj = s_allEombject.find(p->GetGuid());
				if (obj != s_allEombject.end())
					s_allEombject.erase(obj);
				
				p->Free();
				delete p;
				p = nullptr;
			}
		});

		if (!spOut)
		{
			return false;
		}

		EombjectSp spEombject = std::dynamic_pointer_cast<Eombject>(spOut);

		spEombject->Register(spEombject);

		if (!spEombject->RegisterDrived(spEombject))
		{
			return false;
		}

		s_allEombject[spEombject->GetGuid()] = spEombject;

		if (!spOut->SetFilePath(filePath))
		{
			spOut.reset();
			return false;
		}

		return true;
	}

	template<typename ChildType, typename Constructor, typename ... ConstructorParams>
	static bool Load(std::shared_ptr<ChildType>& spOut, const Constructor& constructor, const std::string& filePath, const ConstructorParams& ... args)
	{
		if (Find(spOut, filePath))
			return true;

		if (!New(spOut, constructor, filePath, args...))
			return false;

		if (!spOut->Reload(false))
		{
			spOut.reset();
			return false;
		}

		return true;
	}

	template<typename ChildType>
	static bool Find(std::shared_ptr<ChildType>& spOut, const std::string& filePath)
	{
		if (filePath.empty())
			return false;

		if (!std::is_convertible<ChildType*, Eombject*>::value)
		{
			return false;
		}

		auto guid = s_filePathTable.find(filePath);
		if (guid == s_filePathTable.end())
			return false;

		auto resource = s_allEombject.find(guid->second);
		if (resource == s_allEombject.end())
		{
			return false;
		}

		spOut = std::dynamic_pointer_cast<ChildType>(resource->second.lock());
		if (!spOut)
		{
			return false;
		}

		return true;
	}
protected:
	virtual bool Register(std::shared_ptr<Eombject> spResource)
	{
		if (!spResource)
			return false;

		if (s_allEombject.find(spResource->GetGuid()) != s_allEombject.end())
		{
			return false;
		}

		if (!spResource->RegisterDrived(spResource))
		{
			return false;
		}

		s_allEombject[spResource->GetGuid()] = spResource;

		return true;
	}

private:
	static uuid_unordered_map<EombjectWp> s_allEombject;
	static std::unordered_map<std::string, boost::uuids::uuid> s_filePathTable;

	static bool CheckAndUpdatefilePathTable(Eombject *pResource, const std::string& newFilePath)
	{
		//if (s_resources.find(pResource->GetGuid()) == s_resources.end())
		//	return false;

		const std::string& currFilePath = pResource->GetFilePath();
		if (currFilePath.compare(newFilePath) == 0)
			return true;

		auto currResource = s_filePathTable.find(currFilePath);

		if (newFilePath.empty())
		{
			if (!currFilePath.empty())
			{
				if (currResource == s_filePathTable.end())
				{
					return false;
				}
				s_filePathTable.erase(currResource);
			}
		}
		else
		{
			auto resource = s_filePathTable.find(newFilePath);
			if (resource == s_filePathTable.end())
			{
				if (!currFilePath.empty())
				{
					if (currResource == s_filePathTable.end())
					{
						return false;
					}
					s_filePathTable.erase(currResource);
				}
				s_filePathTable[newFilePath] = pResource->GetGuid();
			}
			else
			{
				return false;
			}
		}

		return true;
	}
public:
    virtual ~Eombject() override {}
    virtual void Free() final
	{
		_Free();
	}
    virtual bool Reload(bool bFreeBeforeReload) final
	{
		if (bFreeBeforeReload)
			Free();
		return _Reload();
	}
	const std::string& GetFilePath() const { return m_filePath; }
	virtual bool SetFilePath(const std::string& filePath) final
	{
		if (CheckAndUpdatefilePathTable(this, filePath))
		{
			m_filePath = filePath;
			return true;
		}
		return false;
	}

	virtual bool Unregister()
	{
		auto namedResource = s_filePathTable.find(GetFilePath());
		if (namedResource != s_filePathTable.end())
			s_filePathTable.erase(namedResource);

		//auto ressource = s_resources.find(GetGuid());
		//if (ressource == s_resources.end())
		//{
		//	return false;
		//}
		//s_resources.erase(ressource);

		auto obj = s_allEombject.find(GetGuid());
		if (obj == s_allEombject.end())
		{
			return false;
		}
		s_allEombject.erase(obj);

		return true;
	}
protected:
	virtual void _Free() {}
	virtual bool _Reload() { return true; }

	virtual bool RegisterDrived(EombjectSp spObj)
	{
		return spObj != nullptr;
	}

    std::string m_filePath;
};

std::unordered_map<std::string, boost::uuids::uuid> Eombject::s_filePathTable;
uuid_unordered_map<Eombject::EombjectWp> Eombject::s_allEombject;

#endif
