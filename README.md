CyberScanX Documentation

Overview

CyberScanX is a versatile cybersecurity tool designed to perform various security assessments on target systems. It includes functionalities for port scanning, keylogging, and vulnerability scanning. This tool is developed to help security professionals identify potential vulnerabilities and assess the security posture of their targets.
Features
•	Port Scanner: Scans a range of ports on a target IP address to identify open ports and associated services.
•	Keylogger: Logs keystrokes on the local machine and saves them to a file.
•	Vulnerability Scanner: Uses Nmap to perform a fast vulnerability scan on a target IP address.

Requirements
To run CyberScanX, you need the following:
•	Operating System: Windows
•	Compiler: A C compiler that supports Windows API (e.g., MinGW, Visual Studio)
•	Libraries: WinSock2 library
•	Nmap: Installed on the system for vulnerability scanning

Installation
1.	Clone the Repository
2.	Compile the Code:
    gcc -o CyberScanX.exe CyberScanX.c -lws2_32
3.	Install Nmap:
  •	Download and install Nmap from the official website: Nmap Download
  •	Ensure that the Nmap executable is added to your system's PATH.

Usage
1.	Run the Tool:
  ./CyberScanX.exe
2.	Select an Option:
•	The tool will display a menu with the following options:
  .	Port Scanner
  .	Keylogger
  .	Vulnerability Scanner
  .	Exit
3.	Port Scanner:
  •	Enter the target IP address when prompted.
  •	The tool will scan the first 100 ports and display the open ports along with their associated services.
4.	Keylogger:
  •	The keylogger will start and log keystrokes to keylog.txt.
  •	Press Ctrl+C to stop the keylogger.
5.	Vulnerability Scanner:
  •	Enter the target IP address when prompted.
  •	The tool will run a fast vulnerability scan using Nmap and display the results.

![image](https://github.com/user-attachments/assets/ed7b055b-0dc8-4d9b-9f82-dbfd84549505)

https://drive.google.com/file/d/1-YFFEWjG5knWhSfEq4f6h9HFY21sU7aS/view?usp=sharing
