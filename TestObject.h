#pragma once

#include "Resource.h"


template<typename Current, typename Parent>
class Collection : public Parent
{
public:
	using CurrentWp = std::weak_ptr<Current>;
	using CurrentSp = std::shared_ptr<Current>;

	bool Unregister() override
	{
		bool bResult = Parent::Unregister();
		auto obj = s_objects.find(GetGuid());
		if (obj != s_objects.end())
		{
			s_objects.erase(obj);
		}
		else
		{
			bResult = false;
		}

		return bResult;
	}
protected:
	virtual bool Register(Eombject::EombjectSp spObj) override
	{
		Parent::Register(spObj);
		s_objects[spObj->GetGuid()] = std::dynamic_pointer_cast<Current>(spObj);
		return true;
	}
public:
	static uuid_unordered_map<CurrentWp> s_objects;
};

class GameObject : public Collection<GameObject, Eombject>
{

};

uuid_unordered_map<Collection<GameObject, Eombject>::CurrentWp> Collection<GameObject, Eombject>::s_objects;

class Character : public Collection<Character, GameObject>
{
};

uuid_unordered_map<Collection<Character, GameObject>::CurrentWp> Collection<Character, GameObject>::s_objects;