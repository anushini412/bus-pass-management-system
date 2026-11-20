
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void printResult(char name[], int sequence[], int n,
                 int head, int total) {
    int i, current = head, movement = 0;

    printf("\n--- %s ---\n", name);
    printf("Head movement sequence: %d", head);

    for (i = 0; i < n; i++) {
        printf(" -> %d", sequence[i]);
        movement += abs(current - sequence[i]);
        current = sequence[i];
    }

    printf("\nTotal head movement: %d tracks\n", movement);
    printf("Average head movement: %.2f tracks\n",
           (float)movement / n);
    printf("Average waiting time (movement units): %.2f\n",
           (float)total / n);
}

void fcfs(int a[], int n, int head) {
    int seq[MAX], total = 0, current = head;

    for (int i = 0; i < n; i++) {
        seq[i] = a[i];
        total += abs(current - seq[i]);
        current = seq[i];
    }

    printResult("FCFS", seq, n, head, total);
}

void sstf(int a[], int n, int head) {
    int visited[MAX] = {0};
    int seq[MAX], total = 0, current = head;

    for (int i = 0; i < n; i++) {
        int min = 100000, index = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] &&
                abs(current - a[j]) < min) {
                min = abs(current - a[j]);
                index = j;
            }
        }

        seq[i] = a[index];
        visited[index] = 1;
        total += min;
        current = a[index];
    }

    printResult("SSTF", seq, n, head, total);
}

void scan(int a[], int n, int head,
          int diskSize, int direction) {
    int b[MAX], seq[MAX], k = 0, total = 0;
    int current = head, i, j, temp;

    for (i = 0; i < n; i++)
        b[i] = a[i];

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (b[j] > b[j + 1]) {
                temp = b[j];
                b[j] = b[j + 1];
                b[j + 1] = temp;
            }
        }
    }

    if (direction == 1) {
        for (i = 0; i < n; i++)
            if (b[i] >= head)
                seq[k++] = b[i];

        if (k > 0 && k < n) {
            total += abs(current - (diskSize - 1));
            current = diskSize - 1;
        }

        for (i = n - 1; i >= 0; i--)
            if (b[i] < head)
                seq[k++] = b[i];
    } else {
        for (i = n - 1; i >= 0; i--)
            if (b[i] <= head)
                seq[k++] = b[i];

        if (k > 0 && k < n) {
            total += current;
            current = 0;
        }

        for (i = 0; i < n; i++)
            if (b[i] > head)
                seq[k++] = b[i];
    }

    for (i = 0; i < k; i++) {
        total += abs(current - seq[i]);
        current = seq[i];
    }

    printResult("SCAN", seq, k, head, total);
}

int main() {
    int n, a[MAX], head, diskSize, direction;

    printf("DISK SCHEDULING PERFORMANCE\n");
    printf("Enter number of disk requests (1-100): ");
    scanf("%d", &n);

    if (n < 1 || n > MAX) {
        printf("Invalid number of requests.\n");
        return 1;
    }

    printf("Enter disk size (number of tracks): ");
    scanf("%d", &diskSize);

    if (diskSize < 2) {
        printf("Invalid disk size.\n");
        return 1;
    }

    printf("Enter disk request queue:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);

        if (a[i] < 0 || a[i] >= diskSize) {
            printf("Invalid track number.\n");
            return 1;
        }
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    if (head < 0 || head >= diskSize) {
        printf("Invalid head position.\n");
        return 1;
    }

    printf("Enter SCAN direction (1=Right, 0=Left): ");
    scanf("%d", &direction);

    if (direction != 0 && direction != 1) {
        printf("Invalid direction.\n");
        return 1;
    }

    fcfs(a, n, head);
    sstf(a, n, head);
    scan(a, n, head, diskSize, direction);

    return 0;
}
