///////////////////////////////////////////////////////////////////////////////////
/// OpenGL Image (gli.g-truc.net)
///
/// Copyright (c) 2008 - 2015 G-Truc Creation (www.g-truc.net)
/// Permission is hereby granted, free of charge, to any person obtaining a copy
/// of this software and associated documentation files (the "Software"), to deal
/// in the Software without restriction, including without limitation the rights
/// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
/// copies of the Software, and to permit persons to whom the Software is
/// furnished to do so, subject to the following conditions:
/// 
/// The above copyright notice and this permission notice shall be included in
/// all copies or substantial portions of the Software.
/// 
/// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
/// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
/// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
/// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
/// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
/// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
/// THE SOFTWARE.
///
/// @ref core
/// @file gli/core/dx.inl
/// @date 2013-11-09 / 2013-11-09
/// @author Christophe Riccio
///////////////////////////////////////////////////////////////////////////////////

namespace gli
{
	inline dx::dx()
	{
		static format const Table[] =
		{
			// unorm formats
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8_UNORM, glm::u32vec4(0x00FF0000, 0x00000000, 0x00000000, 0x00000000)},			//R8_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8_UNORM, glm::u32vec4(0x00FF0000, 0x0000FF00, 0x00000000, 0x00000000)},		//RG8_UNORM,
			{DDPF_RGB, D3DFMT_R8G8B8, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0x00FF0000, 0x0000FF00, 0x000000FF, 0x00000000)},			//RGB8_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_UNORM, glm::u32vec4(0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000)},	//RGBA8_UNORM,

			{DDPF_FOURCC, D3DFMT_L16, DXGI_FORMAT_R16_UNORM, glm::u32vec4(0x0000FFFF, 0x00000000, 0x00000000, 0x00000000)},			//R16_UNORM,
			{DDPF_FOURCC, D3DFMT_G16R16, DXGI_FORMAT_R16G16_UNORM, glm::u32vec4(0x0000FFFF, 0xFFFF0000, 0x00000000, 0x00000000)},	//RG16_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//RGB16_UNORM,
			{DDPF_FOURCC, D3DFMT_A16B16G16R16, DXGI_FORMAT_R16G16B16A16_UNORM, glm::u32vec4(0)},	//RGBA16_UNORM,

			// snorm formats
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8_SNORM, glm::u32vec4(0)},					//R8_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8_SNORM, glm::u32vec4(0)},				//RG8_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//RGB8_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_SNORM, glm::u32vec4(0)},			//RGBA8_SNORM,

			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16_SNORM, glm::u32vec4(0)},					//R16_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16_SNORM, glm::u32vec4(0)},				//RG16_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//RGB16_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16B16A16_SNORM, glm::u32vec4(0)},		//RGBA16_SNORM,

			// Unsigned integer formats
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8_UINT, glm::u32vec4(0)},					//R8U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8_UINT, glm::u32vec4(0)},					//RG8U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//RGB8U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_UINT, glm::u32vec4(0)},				//RGBA8U,

			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16_UINT, glm::u32vec4(0)},					//R16U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16_UINT, glm::u32vec4(0)},				//RG16U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//RGB16U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16B16A16_UINT, glm::u32vec4(0)},			//RGBA16U,

			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32_UINT, glm::u32vec4(0)},					//R32U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32_UINT, glm::u32vec4(0)},				//RG32U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32_UINT, glm::u32vec4(0)},			//RGB32U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32A32_UINT, glm::u32vec4(0)},			//RGBA32U,

			/// Signed integer formats
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8_SINT, glm::u32vec4(0)},					//R8I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8_SINT, glm::u32vec4(0)},					//RG8I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//RGB8I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_SINT, glm::u32vec4(0)},				//RGBA8I,

			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16_SINT, glm::u32vec4(0)},					//R16I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16_SINT, glm::u32vec4(0)},				//RG16I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//RGB16I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R16G16B16A16_SINT, glm::u32vec4(0)},			//RGBA16I,

			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32_SINT, glm::u32vec4(0)},					//R32I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32_SINT, glm::u32vec4(0)},				//RG32I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32_SINT, glm::u32vec4(0)},			//RGB32I,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32A32_SINT, glm::u32vec4(0)},			//RGBA32I,

			/// Floating formats
			{DDPF_FOURCC, D3DFMT_R16F, DXGI_FORMAT_R16_FLOAT, glm::u32vec4(0)},						//R16F,
			{DDPF_FOURCC, D3DFMT_G16R16F, DXGI_FORMAT_R16G16_FLOAT, glm::u32vec4(0)},				//RG16F,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//RGB16F,
			{DDPF_FOURCC, D3DFMT_A16B16G16R16F, DXGI_FORMAT_R16G16B16A16_FLOAT, glm::u32vec4(0)},	//RGBA16F,

			{DDPF_FOURCC, D3DFMT_R32F, DXGI_FORMAT_R32_FLOAT, glm::u32vec4(0xFFFFFFFF, 0x0000000, 0x0000000, 0x0000000)},			//R32F,
			{DDPF_FOURCC, D3DFMT_G32R32F, DXGI_FORMAT_R32G32_FLOAT, glm::u32vec4(0)},				//RG32F,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R32G32B32_FLOAT, glm::u32vec4(0)},				//RGB32F,
			{DDPF_FOURCC, D3DFMT_A32B32G32R32F, DXGI_FORMAT_R32G32B32A32_FLOAT, glm::u32vec4(0)},	//RGBA32F,

			/// sRGB formats
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//SR8,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//SRG8,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB, glm::u32vec4(0)},			//SRGB8,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R8G8B8A8_UNORM_SRGB, glm::u32vec4(0)},			//SRGB8_ALPHA8,

			/// Packed formats
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R10G10B10A2_UNORM, glm::u32vec4(0x3FF00000, 0x000FFC00, 0x000003FF, 0xC0000000)},	//RGB10A2_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R10G10B10A2_UINT, glm::u32vec4(0)},													//RGB10A2U,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R9G9B9E5_SHAREDEXP, glm::u32vec4(0)},												//RGB9E5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_R11G11B10_FLOAT, glm::u32vec4(0)},													//RG11B10F,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0x70, 0x38, 0xC0, 0x00)},										//RG3B2,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_B5G6R5_UNORM, glm::u32vec4(0xf800, 0x07e0, 0x001f, 0x0000)},							//R5G6B5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_B5G5R5A1_UNORM, glm::u32vec4(0x7c00, 0x03e0, 0x001f, 0x8000)},						//RGB5A1,
			{DDPF_FOURCC, D3DFMT_A4R4G4B4, DXGI_FORMAT_B4G4R4A4_UNORM, glm::u32vec4(0x0F00, 0x00F0, 0x000F, 0xF000)},					//RGBA4,

			/// Swizzle formats
			{DDPF_RGB, D3DFMT_R8G8B8, DXGI_FORMAT_B8G8R8X8_UNORM, glm::u32vec4(0x00FF0000, 0x0000FF00, 0x000000FF, 0x00000000)},		//FORMAT_BGRX8_UNORM,
			{DDPF_RGBA, D3DFMT_A8R8G8B8, DXGI_FORMAT_B8G8R8A8_UNORM, glm::u32vec4(0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000)},		//BGRA8_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_B8G8R8X8_UNORM_SRGB, glm::u32vec4(0x00FF0000, 0x0000FF00, 0x000000FF, 0x00000000)},	//SBGR8_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_B8G8R8A8_UNORM_SRGB, glm::u32vec4(0x00FF0000, 0x0000FF00, 0x000000FF, 0xFF000000)},	//SBGR8_ALPHA8_UNORM,

			/// Luminance Alpha formats
			{DDPF_LUMINANCE, D3DFMT_L8, DXGI_FORMAT_R8_UNORM, glm::u32vec4(0x000000FF, 0x00000000, 0x00000000, 0x00000000)},				//L8_UNORM,
			{DDPF_ALPHA, D3DFMT_A8, DXGI_FORMAT_R8_UNORM, glm::u32vec4(0x00000000, 0x00000000, 0x00000000, 0x000000FF)},					//A8_UNORM,
			{DDPF_LUMINANCE_ALPHA, D3DFMT_A8L8, DXGI_FORMAT_R8G8_UNORM, glm::u32vec4(0x000000FF, 0x00000000, 0x00000000, 0x0000FF00)},		//LA8_UNORM,
			{DDPF_LUMINANCE, D3DFMT_L16, DXGI_FORMAT_R16_UNORM, glm::u32vec4(0x0000FFFF, 0x00000000, 0x00000000, 0x00000000)},				//L16_UNORM,
			{DDPF_ALPHA, D3DFMT_UNKNOWN, DXGI_FORMAT_R16_UNORM, glm::u32vec4(0x00000000, 0x00000000, 0x00000000, 0x0000FFFF)},				//A16_UNORM,
			{DDPF_LUMINANCE_ALPHA, D3DFMT_UNKNOWN, DXGI_FORMAT_R16_UNORM, glm::u32vec4(0x0000FFFF, 0x00000000, 0x00000000, 0xFFFF0000)},	//LA16_UNORM,

			/// Depth formats
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_D16_UNORM, glm::u32vec4(0)},						//D16,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//D24X8,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_D24_UNORM_S8_UINT, glm::u32vec4(0)},				//D24S8,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_D32_FLOAT, glm::u32vec4(0)},						//D32F,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_D32_FLOAT_S8X24_UINT, glm::u32vec4(0)},			//D32FS8X24,

			/// Compressed formats
			{DDPF_FOURCC, D3DFMT_DXT1, DXGI_FORMAT_BC1_UNORM, glm::u32vec4(0)},						//RGB_DXT1,
			{DDPF_FOURCC_ALPHAPIXELS, D3DFMT_DXT1, DXGI_FORMAT_BC1_UNORM, glm::u32vec4(0)},			//RGBA_DXT1,
			{DDPF_FOURCC_ALPHAPIXELS, D3DFMT_DXT3, DXGI_FORMAT_BC2_UNORM, glm::u32vec4(0)},			//RGBA_DXT3,
			{DDPF_FOURCC_ALPHAPIXELS, D3DFMT_DXT5, DXGI_FORMAT_BC3_UNORM, glm::u32vec4(0)},			//RGBA_DXT5,
			{DDPF_FOURCC, D3DFMT_ATI1, DXGI_FORMAT_BC4_UNORM, glm::u32vec4(0)},						//R_ATI1N_UNORM,
			{DDPF_FOURCC, D3DFMT_AT1N, DXGI_FORMAT_BC4_SNORM, glm::u32vec4(0)},						//R_ATI1N_SNORM,
			{DDPF_FOURCC, D3DFMT_ATI2, DXGI_FORMAT_BC5_UNORM, glm::u32vec4(0)},						//RG_ATI2N_UNORM,
			{DDPF_FOURCC, D3DFMT_AT2N, DXGI_FORMAT_BC5_SNORM, glm::u32vec4(0)},						//RG_ATI2N_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC6H_UF16, glm::u32vec4(0)},						//RGB_BP_UF16,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC6H_SF16, glm::u32vec4(0)},						//RGB_BP_SF16,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC7_UNORM, glm::u32vec4(0)},						//RGB_BP_UNORM,
			{DDPF_FOURCC, D3DFMT_POWERVR_4BPP, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},				//RGB_PVRTC_4BPP,
			{DDPF_FOURCC, D3DFMT_POWERVR_2BPP, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},				//RGB_PVRTC_2BPP,
			{DDPF_FOURCC, D3DFMT_POWERVR_4BPP, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},				//RGBA_PVRTC_4BPP,
			{DDPF_FOURCC, D3DFMT_POWERVR_2BPP, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},				//RGBA_PVRTC_2BPP,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//RGBA_PVRTC2_4BPP,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//RGBA_PVRTC2_2BPP,
			{DDPF_FOURCC, D3DFMT_ATC, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//ATC_RGB,
			{DDPF_FOURCC, D3DFMT_ATCA, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//ATC_RGBA_EXPLICIT_ALPHA,
			{DDPF_FOURCC, D3DFMT_ATCI, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//ATC_RGBA_INTERPOLATED_ALPHA,
			{DDPF_FOURCC, D3DFMT_ETC, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//FORMAT_RGB_ETC_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//FORMAT_RGB2_ETC_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//RGBA_ETC2_PUNCHTHROUGH_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//RGBA_ETC2_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//R11_EAC_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//R11_EAC_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//RG11_EAC_UNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//RG11_EAC_SNORM,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_4X4_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_4x4,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_5X4_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_5x4,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_5X5_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_5x5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_6X5_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_6x5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_6X6_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_6x6,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X5_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_8x5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X6_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_8x6,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X8_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_8x8,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X5_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_10x5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X6_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_10x6,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X8_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_10x8,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X10_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_10x10,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_12X10_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_12x10,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_12X12_UNORM, glm::u32vec4(0)},				//RGBA_ASTC_12x12,

			// Compressed sRGB formats
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC1_UNORM_SRGB, glm::u32vec4(0)},				//FORMAT_RGB_DXT1_SRGB,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC1_UNORM_SRGB, glm::u32vec4(0)},				//FORMAT_RGBA_DXT1_SRGB,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC2_UNORM_SRGB, glm::u32vec4(0)},				//FORMAT_RGBA_DXT3_SRGB,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC3_UNORM_SRGB, glm::u32vec4(0)},				//FORMAT_RGBA_DXT5_SRGB,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_BC7_UNORM_SRGB, glm::u32vec4(0)},				//FORMAT_RGB_BP_SRGB,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//FORMAT_RGB_PVRTC1_8X8_SRGB,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//FORMAT_RGB_PVRTC1_16X8_SRGB,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//FORMAT_RGBA_PVRTC1_8X8_SRGB,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//FORMAT_RGBA_PVRTC1_16X8_SRGB,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//FORMAT_RGBA_PVRTC2_8X8_SRGB,
			{DDPF_FOURCC, D3DFMT_UNKNOWN, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},					//FORMAT_RGBA_PVRTC2_16X8_SRGB,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//FORMAT_RGB_ETC_SRGB,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//FORMAT_RGBA_ETC2_PUNCHTHROUGH_SRGB,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_UNKNOWN, glm::u32vec4(0)},						//FORMAT_RGBA_ETC2_SRGB,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_4X4_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_4x4,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_5X4_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_5x4,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_5X5_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_5x5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_6X5_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_6x5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_6X6_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_6x6,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X5_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_8x5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X6_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_8x6,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_8X8_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_8x8,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X5_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_10x5,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X6_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_10x6,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X8_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_10x8,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_10X10_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_10x10,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_12X10_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_12x10,
			{DDPF_FOURCC, D3DFMT_DX10, DXGI_FORMAT_ASTC_12X12_UNORM_SRGB, glm::u32vec4(0)},			//SRGB_ALPHA_ASTC_12x12,
		};

		static_assert(sizeof(Table) / sizeof(Table[0]) == FORMAT_COUNT, "GLI error: format descriptor list doesn't match number of supported formats");

		std::copy(&Table[0], &Table[0] + FORMAT_COUNT, this->Translation.begin());
	}

	inline dx::format const & dx::translate(gli::format const & Format) const
	{
		return Translation[Format];
	}

	inline gli::format dx::find(dx::D3DFORMAT FourCC)
	{
		for(int FormatIndex = 0; FormatIndex < FORMAT_COUNT; ++FormatIndex)
		{
			if(this->Translation[FormatIndex].D3DFormat != FourCC)
				continue;
			return static_cast<gli::format>(FormatIndex);
		}
		return static_cast<gli::format>(FORMAT_INVALID);
	}

	inline gli::format dx::find(dx::dxgiFormat Format)
	{
		for(int FormatIndex = 0; FormatIndex < FORMAT_COUNT; ++FormatIndex)
		{
			if(this->Translation[FormatIndex].DXGIFormat != Format)
				continue;
			return static_cast<gli::format>(FormatIndex);
		}
		return static_cast<gli::format>(FORMAT_INVALID);
	}
}//namespace gli
