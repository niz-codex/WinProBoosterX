#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


//optimizer section
void cleanSys();
void networkOptimize(const char* interface_id);
void lowLatency();
void repairSystem();

void finalMessage(const char* optimize_name);
void wait(int seconds);
void clearScreen();

void showMenu();
int authenticate();
void showEULA();

//FINE
int main() {
    system("title WinProBoosterX v1.0.0");
    system("color 0A");

    printf("Checking admin privileges...\n");
    system("net session >nul 2>&1");
    if (system("if not \"%errorlevel%\"==\"0\" exit 1") != 0) {
        printf("[-] This program must be run as administrator.\n");
        wait(5);
        return 1;
    }

    if (!authenticate()) {
        printf("[-] Incorrect password. Exiting...\n");
        wait(5);
        return 1;
    }

    showMenu();
    return 0;
}
//FINE
int authenticate() {
    char password[64];
    printf("Enter password: ");
    scanf("%s", password);
    return strcmp(password, "admin123") == 0; // Replace with your actual password
}

//FINE
void finalMessage(const char* optimize_name) {
    printf("[*] %s optimizing is finished...\n", optimize_name);
}

//FINE
void wait(int seconds){
    char command[64];
    sprintf(command, "timeout /t %d >nul", seconds);
    system(command);
}

//FINE
void clearScreen(){
    system("cls");
}

//FINE
void cleanSys(){
    clearScreen();
    char msg[32] = "Clean system";
    printf("[*] System Cleaning is Starting...\n");
    // Clean temp folder
    system("del /q /f /s %TEMP%\\*.* ");
    // Cleanup windows temp
    system("del /q /f /s C:\\windows\\temp\\*.*");
    //Flush dns cache
    system("ipconfig /flushdns");
    //Enable ultimate perfomance mode
    system("powercfg -duplicatescheme e9a42b02-d5df-448d-aa00-03f14749eb61");
    //Startup apps launch faster "also you can get quick boot experiance"
    system("reg add \"HKCU\\Software\\Microsoft\\CurrentVersion\\EXplorer\\Serialize\" /v StartuopDelayInMSec /t/ REG_DWORD /d 0 /f");
    //Disble superfetch
    system("sc stop \"SysMain\" && sc config \"SysMain\" start= disabled");
    //Disable NDU (Network Diagnostic usage data)
    system("reg add \"HKLM\\SYSTEM\\ControlSet001\\Services\\Ndu\" /v Start /t REG_DWORD /d 4 /f");
    //Enable Hardware-accelerated GPU scheduling
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\GraphicsDrivers\" /v HwSchMode /t REG_DWORD /d 2 /f");
    finalMessage(msg);
    wait(5);
}
//FINE
void networkOptimize(const char* interface_id){
    clearScreen();
    char msg[32] = "Network";
    char command[512];
    char command1[512];
    //Disable TCP Auto-Tuning
    system("netsh interface tcp set global autotuninglevel=disabled");
    //Disable Nagle Algorithm
    snprintf(command, sizeof(command),"reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces\\%s\" /v TcpAckFrequency /t REG_DWORD /d 1 /f", interface_id);
    snprintf(command1, sizeof(command1), "reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Services\\Tcpip\\Parameters\\Interfaces\\%s\" /v TCPNoDelay /t REG_DWORD /d 1 /f", interface_id);
    system(command);
    system(command1);
    finalMessage(msg);
    wait(5);
}
//FINE
void lowLatency(){
    clearScreen();
    char msg[] = "Low latency";
    printf("[*] Optimizing Low letency Started...\n\n");
    //Disable Mouse Acceleration
    system("reg add \"HKCU\\Control Panel\\Mouse\" /v MouseSpeed /t REG_SZ /d 0 /f");
    system("reg add \"HKCU\\Control Panel\\Mouse\" /v MouseThreshold1 /t REG_SZ /d 0 /f");
    system("reg add \"HKCU\\Control Panel\\Mouse\" /v MouseThreshold2 /t REG_SZ /d 0 /f");
    //Always Unpark Cores
    system("reg add \"HKLM\\SYSTEM\\CurrentControlSet\\Control\\Power\\PowerSettings\\54533251-82be-4824-96c1-47b60b740d00\\0cc5b647-c1df-4637-891a-dec35c318583\" /v Attributes /t REG_DWORD /d 2 /f");
    finalMessage(msg);
    wait(5);
}
//FINE
void repairSystem(){
    clearScreen();
    char msg[] = "System repair";
    printf("[*] Running System Repair (DISM + SFC)...\n\n");

    system("DISM /Online /Cleanup-Image /RestoreHealth");
    system("sfc /scannow");

    finalMessage(msg);
    wait(5);
}

//FINE
void showEULA(){
    clearScreen();
    printf("=================================================\n");
    printf("|          WinProBoosterX v1.0.0 - EULA         |\n");
    printf("|             Created by Nizath                 |\n");
    printf("=================================================\n");
    printf("1. This software is provided \"as-is\".\n");
    printf("2. No liability for system changes or data loss.\n");
    printf("3. Do not reverse-engineer or redistribute.\n");
    printf("4. For personal optimization use only.\n");
    printf("5. Use at your own risk.\n");
    printf("=================================================\n");
    system("pause");
}

/*defender cleaner*/
//FINE
void showMenu() {
    int choice;
    while (1) {
        clearScreen();
        printf("===== WinProBoosterX v1.0.0 by Nizath =====\n");
        printf("[1] Clean System\n");
        printf("[2] Network Optimizer\n");
        printf("[3] Low Letency Fix\n");
        printf("[4] Repair System (DISM + SFC)\n");
        printf("[5] Show EULA\n");
        printf("[0] Exit\n");
        printf("===========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // to consume newline
        switch (choice) {
            case 1: 
                cleanSys(); 
                break;
            case 2: 
                networkOptimize("Wi-Fi"); //provide your interface id here
                break;
            case 3: 
                lowLatency(); 
                break;
            case 4: 
                repairSystem(); 
                break;
            case 5: 
                showEULA(); 
                break;
            case 0: 
                exit(0);
            default: printf("Invalid choice.\n"); wait(1); 
                break;
        }
    }
}

