struct LayerProperties {
	VkLayerProperties properties;
	std::vector<VkExtensionProperties> extensions;
}

class VulkanLayerAndExtension {
	std::vector<LayerProperties> layerPropertyList;
	VkResult getInstanceLayerProperties();
	VkResult getExtensionProperties(LayerProperties &layerProps, VkPhysicalDevice* gpu=NULL);
	VkResult getDeviceExtensionProperties(VKPhysicalDevice *gpu);
}
