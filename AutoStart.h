//#define UNICODE
//#define _UNICODE

#ifndef AUTOSTART_H
#define AUTOSTART_H

#include <tchar.h>
#include <wchar.h>
#include <windows.h>

std::wstring getCurrentDirectoryOnWindows()
{
    const unsigned long maxDir = 260;
    WCHAR currentDir[maxDir];
    GetCurrentDirectoryW(maxDir, currentDir);
    return std::wstring(currentDir);
}
void RunApplicationOnStartup()
{
 // std::wstring Path[MAX_PATH];
//GetModuleFileName(NULL,Path,MAX_PATH);

std::wstring progPath = getCurrentDirectoryOnWindows();
HKEY hkey = NULL;
LONG createStatus = RegCreateKeyW(HKEY_CURRENT_USER, L"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", &hkey); //Creates a key
LONG status = RegSetValueExW(hkey, L"Keyboard-", 0, REG_SZ, (BYTE *)progPath.c_str(), (progPath.size()+1) * sizeof(wchar_t));
//RegCloseKey(hkey);

}

#endif // AUTOSTART_H
