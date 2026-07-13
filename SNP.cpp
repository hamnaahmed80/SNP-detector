#include <stdio.h>
#include <string.h>
#include <ctype.h>
bool check_seq(char seq1[], char seq2[]) {
    // lengths match
    if (strlen(seq1) != strlen(seq2)) {
        printf("Error: Sequences must be of equal length.\nPlease enter correct sequence again.\n");
        return false;     // Stop and return false if lengths are different
    }

    for (int i = 0; seq1[i]; i++) {
        seq1[i] = toupper(seq1[i]);
        if (seq1[i] != 'A' && seq1[i] != 'T' && seq1[i] != 'C' && seq1[i] != 'G') {
            printf("Error: Invalid character '%c' in first sequence.\nPlease enter correct sequence again. Only A, T, C, G are allowed.\n", seq1[i]);
            return false;  // Return false if invalid character is found
        }
    }

    for (int i = 0; seq2[i]; i++) {
        seq2[i] = toupper(seq2[i]);
        if (seq2[i] != 'A' && seq2[i] != 'T' && seq2[i] != 'C' && seq2[i] != 'G') {
            printf("Error: Invalid character '%c' in second sequence.\nPlease enter correct sequence again. Only A, T, C, G are allowed.\n", seq2[i]);
            return false;
        }
    }

    return true;    // All checks passed

}

int main() {
    char seq1[1000], seq2[1000];
    char choice;

    do {
        int length = 0;
        int snps = 0;

        do {
            printf("Enter DNA sequence 1: ");
            scanf("%s", seq1);
            printf("Enter DNA sequence 2: ");
            scanf("%s", seq2);
        } while (check_seq(seq1, seq2) == false);

        length = strlen(seq1);

        // Identify positions
        printf("                              ");
        for (int i = 1; i <= length; i++) {
            printf("%3d", i);
        }

        printf("\nConverted Sequence 1 toupper: ");
        for (int i = 0; seq1[i]; i++) {
            printf("%3c", seq1[i]);
        }

        printf("\nConverted Sequence 2 toupper: ");
        for (int i = 0; seq2[i]; i++) {
            printf("%3c", seq2[i]);
        }
        printf("\n");

        // SNPs
        for (int i = 0; i < length; i++) {
            if (seq1[i] != seq2[i]) {
                snps++;
                printf("SNP detected at position %d: %c -> %c\n", i + 1, seq1[i], seq2[i]);
            }
        }
        // Percentage identity
        float identity = ((length - snps) / (float)length) * 100;
        printf("Total SNPs: %d\n", snps);
        printf("Percentage Identity: %.2f%%\n", identity);

        // Ask user if they want to continue
       printf("\nDo you want to compare another pair of sequences? (Y/N): ");
        scanf(" %c", &choice);  
    } while (choice == 'Y' || choice == 'y');

    printf("Program exited. Thank you!\n");
    return 0;
}
