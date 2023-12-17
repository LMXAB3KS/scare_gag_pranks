#include <windows.h>

#define IDD_SHUTDOWN_DIALOG 101
#define IDOK1 102
#define IDOK2 103

INT_PTR CALLBACK ShutdownDialogProc(HWND hwndDlg, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_INITDIALOG:
            return TRUE;

        case WM_COMMAND:
            switch (LOWORD(wParam)) {
                case IDOK1:
                case IDOK2:
                    EndDialog(hwndDlg, LOWORD(wParam));
                    break;
            }
            break;

        case WM_CLOSE:
            EndDialog(hwndDlg, IDCANCEL);
            break;

        default:
            return FALSE;
    }
    return TRUE;
}

int main() {
    // Hide the console window.
    FreeConsole();

    MessageBox(NULL, "Do you want to format your computer? Closing this window will format it. Click on OK to format.", "Read Me.", MB_OK | MB_ICONINFORMATION);

    // Create a dialog box with two "OK" buttons
    int choice = DialogBox(GetModuleHandle(NULL), MAKEINTRESOURCE(IDD_SHUTDOWN_DIALOG), NULL, ShutdownDialogProc);

    // Check which "OK" button was clicked
    if (choice == IDOK1 || choice == IDOK2) {
        //system("shutdown /s /t 0"); //may not work depending on how this is run.
    } else {
        // Handling of other cases
    }

    return 0;
}
