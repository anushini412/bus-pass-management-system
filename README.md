
# Investigating Disk Scheduling Performance

## Project Overview
This project investigates the performance of three disk scheduling algorithms used in Operating Systems.

The algorithms are:
1. First Come First Serve (FCFS)
2. Shortest Seek Time First (SSTF)
3. SCAN Disk Scheduling

## Objectives
- Understand disk scheduling techniques.
- Implement FCFS, SSTF and SCAN using C.
- Compare the total disk head movement.
- Identify an algorithm that can reduce unnecessary head movement.

## Technologies Used
- Programming Language: C
- Operating System: Windows
- Tool: GCC Compiler

## How to Run

1. Download or clone this repository.
2. Open a terminal in the project folder.
3. Compile the program:

   gcc disk_scheduling.c -o disk_scheduling

4. Run the program:

   ./disk_scheduling

## Sample Input

Number of requests: 8
Disk size: 200
Request queue:
98 183 37 122 14 124 65 67
Initial head position: 53
SCAN direction: 1 (Right)

## Algorithms
- FCFS: Processes requests in arrival order.
- SSTF: Selects the request closest to the current head position.
- SCAN: Moves the disk head in one direction, then reverses at the disk boundary.

## Expected Result
The program displays the head movement sequence and total head movement for all three algorithms.

## Conclusion
This project demonstrates how different disk scheduling algorithms affect disk head movement and helps compare their performance.

## Developed By
Department of Computer Science and Engineering
