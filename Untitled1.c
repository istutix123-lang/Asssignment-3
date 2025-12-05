#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showOrder(int order) {
    printf("\nCustomer Order:\n");
    if (order == 1) printf("Veg Burger (Bun + Veg Patty + Ketchup)\n");
    else if (order == 2) printf("Cheese Burger (Bun + Veg Patty + Cheese + Mayo)\n");
    else if (order == 3) printf("Double Patty Burger (Bun + 2 Patties + Ketchup)\n");
    else if (order == 4) printf("Paneer Burger (Bun + Paneer Patty + Mayo)\n");
}

int main() {
    srand(time(NULL));

    int level = 1, lives = 3, score = 0;
    char repeat = 'y';

    printf("====== ADVANCED BURGER GAME ======\n");

    while (repeat == 'y' || repeat == 'Y') {

        printf("\n======= LEVEL %d =======\n", level);

        int order = rand() % 4 + 1;
        showOrder(order);

        int bun, patty, cheese = 2, sauce, extraPatty = 0;

        int timeLimit = 10 - level; // level increases ? time decreases
        int answer;

        printf("\nYou have %d seconds to prepare the burger!\n", timeLimit);

        printf("\nStep 1: Toast Bun? (1.Yes / 2.No): ");
        scanf("%d", &bun);

        printf("Step 2: Choose Patty:\n1.Veg  2.Paneer  3.None: ");
        scanf("%d", &patty);

        printf("Step 3: Add Cheese? (1.Yes / 2.No): ");
        scanf("%d", &cheese);

        printf("Step 4: Add Sauce:\n1.Ketchup  2.Mayo  3.None: ");
        scanf("%d", &sauce);

        printf("Step 5: Add Extra Patty? (1.Yes / 2.No): ");
        scanf("%d", &extraPatty);

        // Check if order is correct
        int correct = 0;

        if (order == 1) {
            if (patty == 1 && sauce == 1)
                correct = 1;
        }
        else if (order == 2) {
            if (patty == 1 && cheese == 1 && sauce == 2)
                correct = 1;
        }
        else if (order == 3) {
            if (patty == 1 && extraPatty == 1 && sauce == 1)
                correct = 1;
        }
        else if (order == 4) {
            if (patty == 2 && sauce == 2)
                correct = 1;
        }

        if (correct) {
            printf("\n? Correct Burger! +10 points\n");
            score += 10;
        } else {
            printf("\n? Wrong Burger! -1 life\n");
            lives--;
        }

        printf("Score: %d   Lives: %d\n", score, lives);

        if (lives <= 0) {
            printf("\nGAME OVER! Final Score: %d\n", score);
            break;
        }

        // Level Up
        if (score >= level * 20) {
            level++;
            printf("\n?? LEVEL UP! Now you're at LEVEL %d!\n", level);
        }

        printf("\nPlay next customer? (y/n): ");
        scanf(" %c", &repeat);
    }

    printf("\nThanks for playing the Advanced Burger Game!\n");
    return 0;
}

