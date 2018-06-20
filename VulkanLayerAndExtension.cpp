#include "Headers.h"
#include <VulkanLayerAndExtension.h>

VkResult VulkanLayerAndExtension::getInstanceLayerProperties()
{
	uint32_t instanceLayerCount;
	std::vector<VkLayerProperties> layerProperties;
	VkResult result;
	
	do {
		result = vkEnumerateInstanceLayerProperties(&instanceLayerCount, NULL);
		if(result)
			return result;
		if(instanceLayerCount == 0)
			return VK_INCOMPLETE;

		layerProperties.resize(instanceLayerCount);
		result = vkEnumerateInstanceLayerProperties(&instanceLayerCount, layerProperties.data());
	} while(result == VK_INCOMPLETE);

	std::cout << "\nInstanced Layers" << std::endl;
	std::cout << "======================" << std::endl;
	
	for(auto globalLayerProp : layerProperties)
	{
		std::cout << "\n" << globalLayerProp.description <<Layer
		   "\n\t|\n\t|--[Layer Name]-> " <<
			globalLayerProp.layerName << "\n";	
		
		LayerProperties layerProps;
		layerprops.properties = globalLayerProp;

		result = getExtensionProperties(layerProps);
		if(result)
		{
			continue;
		}
		
		layerPropertyList.push_back(layerProps);

		for(auto j : layerProps.extensions){
			std::cout << "\t\t|\n\t\t|--
			[Layer Extension]--> "j.extensionName << "\n";
		}
	}

	return result;
}
		
		

	   	   

