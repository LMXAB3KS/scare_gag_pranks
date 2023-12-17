#include <stdio.h>
#include <unistd.h>
#include <string.h>

void fakeDownload(int totalSize, int chunkSize) {
    int progress = 0;
    int downloaded = 0;

    while (downloaded < totalSize) {
        downloaded += chunkSize;
        progress = (downloaded * 100) / totalSize;

        printf("\r");
        for (int i = 0; i < 50; ++i) {
            if (i < progress / 2) {
                printf("\u2588"); // Unicode block character to represent the progress
            } else {
                printf(" ");
            }
        }
        printf(" %d%%", progress);
        fflush(stdout);

        // Simulate some delay (fake download speed)
        usleep(100000); // Sleep for 100,000 microseconds (0.1 seconds)
    }

    printf("\nDownload complete!\n");
}

int main() {
    char mc_in[5];
    printf("Would you like to download Minecraft for Free? (Y/N): ");
    scanf("%s", mc_in);
    
    if (strcmp(mc_in, "y") == 0 || strcmp(mc_in, "Y") == 0) {
        int totalSize = 1024; // Total size to download (just an example value)
        int chunkSize = 10;   // Size of each chunk downloaded in one iteration

        fakeDownload(totalSize, chunkSize);
        usleep(1000000);
        printf("Malware downloaded. Now executing...");
      usleep(10000000);
    } else if (strcmp(mc_in, "n") == 0 || strcmp(mc_in, "N") == 0) {
        printf("Download Cancelled.\n");
    }

    return 0;
}
