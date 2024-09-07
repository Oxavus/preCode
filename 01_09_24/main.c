


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to hold food information
typedef struct {
    char id[5];
    char name[10];
    char type[10];
    int quantity;
    float unitPrice;
} Food;

// Function declarations
void writeMode();
void readMode();
void searchID(Food foodItems[], int count);
void readAll(Food foodItems[], int count);

int main() {
    char mode;

start: // loop if mode is invalid
    printf("********************************************************\n\n\t\t\tPick-Mode\n\n********************************************************\n\t\tr to Read || w to Write\n\tSelect mode : ");
    scanf(" %c", &mode);  // Space before %c to consume newline

    // mode pick
    if (mode == 'w') {
        writeMode();
    } else if (mode == 'r') {
        readMode();
    } else {
        printf("\ninvalid input!!!");
        goto start;
    }
    return 0;
} // end main

void writeMode() { // writeMode use to write to file.
    system("clear");  // Use "cls" instead of "clear" if on Windows
    char switchMode;

    do {
        int idAmount;
        int totalQuantity = 0;
        float totalAmount = 0;

        printf("********************************************************\n\n\t\t\tWrite-Mode\n\n********************************************************\n"); // welcome txt
        printf("\tAmount of Food to Enter : ");
        scanf("%d", &idAmount);

        Food foodItems[idAmount];

        FILE *food;
        food = fopen("food.txt", "a+"); // Append mode so you don't overwrite existing data

        for (int i = 0; i < idAmount; i++) {
            printf("\nFood ID : ");
            scanf("%s", foodItems[i].id);
            printf("Food Name : ");
            scanf("%s", foodItems[i].name);
            printf("Food Type : ");
            scanf("%s", foodItems[i].type);
            printf("Unit Price : ");
            scanf("%f", &foodItems[i].unitPrice);
            printf("Quantity : ");
            scanf("%d", &foodItems[i].quantity);

            totalAmount += (foodItems[i].unitPrice * foodItems[i].quantity);
            totalQuantity += foodItems[i].quantity;

            fprintf(food, "%d     %s      %s          %s        %.2f             %d         %.2f\n", i, foodItems[i].id, foodItems[i].name, foodItems[i].type, foodItems[i].unitPrice, foodItems[i].quantity, foodItems[i].unitPrice * foodItems[i].quantity);
        }

        fprintf(food, "\tTotal Quantity : %d\n\tTotal Amount : %.2f\n", totalQuantity, totalAmount);
        fclose(food);
        system("clear");

        printf("\n\tr to Read food || s to Stop\n\tOption :");
        scanf(" %c", &switchMode);  // Space before %c to consume newline
        if (switchMode == 'r') {
            readMode();
            break;
        }
    } while (switchMode != 's');
}

void readMode() {
    system("clear");
    char mode;
    printf("********************************************************\n\n\t\t\tRead-Mode\n\n********************************************************\n");
    printf("\t\ti to Search ID || a to Print all  \n\tSearch : ");
    scanf(" %c", &mode);


    FILE *food = fopen("food.txt", "r");
    if (food == NULL) {
        printf("Could not open file food.txt\n");
        return;
    }

    int count = 0;
    char line[256];
    while (fgets(line, sizeof(line), food)) {
        count++;
    }
    rewind(food);


    Food foodItems[count];
    int i = 0;
    while (fgets(line, sizeof(line), food) && i < count) {
        sscanf(line, "%*d %s %s %s %f %d", foodItems[i].id, foodItems[i].name, foodItems[i].type, &foodItems[i].unitPrice, &foodItems[i].quantity);
        i++;
    }
    fclose(food);

    if (mode == 'a') {
        readAll(foodItems, count);
    } else if (mode == 'i') {
        searchID(foodItems, count);
    } else {
        printf("\n\tinvalid input!!!\n");
        readMode();
    }
}

void searchID(Food foodItems[], int count) {
    system("clear");
    printf("********************************************************\n\n\t\t\tSearch_ID\n\n********************************************************\n");
    printf("\tPlease Input FoodID that you want to Know : ");
    char id_to_search[5];
    int found = 0;
    scanf(" %s", id_to_search);

    for (int i = 0; i < count; i++) {
        if (strcmp(foodItems[i].id, id_to_search) == 0) {
            printf("\n\tID %s found: \n\n*NO****FOODID****FOODNAME*******TYPE******UNITPRICE******QUANTITY*****AMOUNT\n", id_to_search);
            printf("%d     %s      %s          %s        %.2f             %d         %.2f\n", i, foodItems[i].id, foodItems[i].name, foodItems[i].type, foodItems[i].unitPrice, foodItems[i].quantity, foodItems[i].unitPrice * foodItems[i].quantity);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("ID %s not found in the records.\n", id_to_search);
    }

    char option;
start:
    printf("\na to List All || w to Write to file\n\tOption : ");
    scanf(" %c", &option);

    if (option == 'a') {
        readAll(foodItems, count);
    } else if (option == 'w') {
        writeMode();
    } else {
        printf("\n\tinvalid input!!!\n");
        goto start;
    }
}

void readAll(Food foodItems[], int count) {
    system("clear");
    printf("********************************************************\n\n\t\t\tLIST_OF_FOOD\n\n********************************************************\n");
    printf("*NO****FOODID****FOODNAME*******TYPE******UNITPRICE******QUANTITY*****AMOUNT\n");


int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
    FILE *file;
    int ids[100], id, count = 0;

    // Open the file for reading
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return 1;
    }

    // Read integers from the file into the array
    while (fscanf(file, "%d", &id) != EOF) {
        ids[count++] = id;
    }
    fclose(file);

    // Sort the array using qsort
    qsort(ids, count, sizeof(int), compare);

    // Open the file for writing (overwrite the file)
    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open file: %s\n", filename);
        return 1;
    }

    // Write sorted integers back to the file
    for (int i = 0; i < count; ++i) {
        fprintf(file, "%d\n", ids[i]);
    }
    fclose(file);

    printf("IDs sorted and saved to %s\n", filename);

    char option;
start:
    printf("\ni to Search ID || w to Write to file\n\tOption : ");
    scanf(" %c", &option);  // Space before %c to consume newline

    if (option == 'i') {
        searchID(foodItems, count);
    } else if (option == 'w') {
        writeMode();
    } else {
        printf("\n\tinvalid input!!!\n");
        goto start;
    }
}
