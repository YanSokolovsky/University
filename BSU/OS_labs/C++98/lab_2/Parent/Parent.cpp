#include "parentfunc.h"
int main()
{
    cout << "Enter the size of array: " << endl;
    int sizeOfArray;
    cin >> sizeOfArray;
    string* arr = new string[sizeOfArray];
    cout << "Enter the elements of our array: " << endl;
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> arr[i];
    }
    cout << "enter the number of pixels from left high corner: " << endl;
    int windth;
    cin >> windth;
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    si.dwX = windth;
    si.dwFlags = STARTF_USEPOSITION;
    if (!CreateProcess(NULL, (LPSTR)MakeComandLine("Child.exe", arr, sizeOfArray).c_str(), NULL, NULL, FALSE,
        CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        cout << "The new procss is not created." << endl;
        cout << "Check a name of the process." << endl;
        cout << "Press any key to finish." << endl;
        char trashForWait;
        cin >> trashForWait;
        return 0;
    }
    WaitForSingleObject(pi.hProcess, INFINITE);
    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    return 0;
}