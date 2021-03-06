// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.
// DDPIActiveX.cpp : Implementation of CDDPIActiveXApp and DLL registration.

#include "stdafx.h"
#include "DDPIActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CDDPIActiveXApp theApp;

const GUID CDECL _tlid = {0x709ed462,0xc56b,0x4395,{0xbf,0x5b,0x73,0x78,0xb5,0xc5,0xf9,0xc3}};
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CDDPIActiveXApp::InitInstance - DLL initialization

BOOL CDDPIActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CDDPIActiveXApp::ExitInstance - DLL termination

int CDDPIActiveXApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
