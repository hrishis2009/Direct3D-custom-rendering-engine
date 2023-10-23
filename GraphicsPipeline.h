#pragma once

#if defined(DEBUG) || defined(_DEBUG)
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#endif

#include "DirectXHelper.h"
#include "Win32Application.h"

using namespace DirectX;
using namespace Microsoft::WRL;

class GraphicsPipeline 
{
public:
	GraphicsPipeline(UINT width, UINT height, std::wstring name);
	void Initialize();
	void Update();
	void Render();
	void Destroy();

private:
	static const UINT FrameCount = 2;

	//the following may need to be public
	UINT m_width;
	UINT m_height;
	float m_aspectRatio;

	std::wstring m_title;
	std::wstring m_assetsPath;
	std::wstring m_title;


	void InitializePipeline();
	void InitializeAssets();

	ComPtr<ID3D12Device> m_d3dDevice;
	ComPtr<ID3D12CommandQueue> m_cmdQueue;
	ComPtr<ID3D12CommandAllocator> m_cmdAllocator;
	ComPtr<ID3D12CommandList> m_cmdList;
	ComPtr<IDXGISwapChain3> m_swapChain;
	ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
	ComPtr<ID3D12RootSignature> m_rootSignature;

	UINT m_frameIndex;

	UINT m_rtvDescriptorSize;
	ComPtr<ID3D12Resource> m_renderTargets[FrameCount];

	void ParseCommandLineArgs(_In_reads_(argc) WCHAR* argv[], int argc);
};