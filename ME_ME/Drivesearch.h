#pragma once
#include <fileapi.h>
#include <WinBase.h>
#include <crtdbg.h>
#include <stdio.h>
#include <WinSock2.h>
#include <Windows.h>
#include <string>
#include <iostream>
#include <thread>
#include <array>
#include <fstream>;
#include <stack>;
using namespace std;
int __cdecl Drivers()
{
    DWORD cchBuffer;
    WCHAR* driveStrings;
    UINT driveType;
    PWSTR driveTypeString;
    ULARGE_INTEGER freeSpace;
    cchBuffer = GetLogicalDriveStrings(0, NULL);

    driveStrings = (WCHAR*)malloc((cchBuffer + 1) * sizeof(TCHAR));
    if (driveStrings == NULL)
    {
        return -1;
    } 
    GetLogicalDriveStrings(cchBuffer, driveStrings);
    while (*driveStrings)
    {
        driveType = GetDriveType(driveStrings);
        GetDiskFreeSpaceEx(driveStrings, &freeSpace, NULL, NULL);

        switch (driveType)
        {
        case DRIVE_FIXED:
            driveTypeString = (PWSTR)L"Hard disk";

            break;

        case DRIVE_CDROM:
            driveTypeString = (PWSTR)L"CD/DVD";
            break;

        case DRIVE_REMOVABLE:
            driveTypeString = (PWSTR)L"Removable";
            break;

        case DRIVE_REMOTE:
            driveTypeString = (PWSTR)L"Network";
            break;
        default:
            driveTypeString = (PWSTR)L"Unknown";
            break;
        }

        printf("%S - %S - %I64u GB free\n", driveStrings, driveTypeString,
            freeSpace.QuadPart / 1024 / 1024 / 1024);
        driveStrings += lstrlen(driveStrings) + 1;
    }

    free(driveStrings);
    return 1;

}