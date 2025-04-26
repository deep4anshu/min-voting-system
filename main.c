#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 100
#define NAME_LENGTH 50

// Structure to store candidate info
struct Candidate {
    char name[NAME_LENGTH];
    int votes;
};

// Global array of candidates
struct Candidate candidates[MAX_CANDIDATES] = {
    {"Ram", 0},
    {"Sita", 0},
    {"Hari", 0}
};
int candidateCount = 3; // Initial candidate count

// Function declarations
void castVote();
void votesCount();
void getLeadingCandidate();
void registerCandidate();
void menu();

// Main function
int main() {
    menu();  // Start the menu
    return 0;
}

// Function to display the menu and handle user choice
void menu() {
    int choice;
    do {
        printf("\n*** Voting System ***\n");
        printf("1. Cast Vote\n");
        printf("2. View Vote Count\n");
        printf("3. View Leading Candidate\n");
        printf("4. Register as a Candidate\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                castVote();
                break;
            case 2:
                votesCount();
                break;
            case 3:
                getLeadingCandidate();
                break;
            case 4:
                registerCandidate();
                break;
            case 5:
                printf("Thank you for using the system!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);
}

// Function to cast a vote
void castVote() {
    int vote;
    printf("\n--- Cast Your Vote ---\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i+1, candidates[i].name);
    }
    printf("Enter your choice (1-%d): ", candidateCount);
    scanf("%d", &vote);

    if(vote >= 1 && vote <= candidateCount) {
        candidates[vote - 1].votes++;
        printf("Thank you for voting!\n");
    } else {
        printf("Invalid vote! Please try again.\n");
    }
}

// Function to view the vote count of all candidates
void votesCount() {
    printf("\n--- Vote Count ---\n");
    for(int i = 0; i < candidateCount; i++) {
        printf("%s - %d votes\n", candidates[i].name, candidates[i].votes);
    }
}

// Function to find and display the leading candidate
void getLeadingCandidate() {
    int maxVotes = 0;
    int winnerIndex = -1;

    for(int i = 0; i < candidateCount; i++) {
        if(candidates[i].votes > maxVotes) {
            maxVotes = candidates[i].votes;
            winnerIndex = i;
        }
    }

    if(winnerIndex != -1) {
        printf("\nLeading Candidate: %s with %d votes\n", candidates[winnerIndex].name, maxVotes);
    } else {
        printf("\nNo votes cast yet.\n");
    }
}

// Function to register a new candidate
void registerCandidate() {
    if(candidateCount >= MAX_CANDIDATES) {
        printf("Candidate limit reached!\n");
        return;
    }
    printf("\n--- Register as a New Candidate ---\n");
    printf("Enter your name: ");
    scanf(" %[^\n]", candidates[candidateCount].name); // Take full name input
    candidates[candidateCount].votes = 0;
    candidateCount++;
    printf("You have been registered as a candidate!\n");
}
