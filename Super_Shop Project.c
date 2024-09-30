#include <stdio.h>
#include <string.h>
#include <malloc.h>

struct node
{
    char productName[50];
    int productPrice;
    int productQuantity;
    int productTotalBill;
    struct node *next;
};
struct node *head = NULL;

void purchase(int p, int q)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (p == 1)
    {
        strcpy(n->productName, "BAT");
        n->productPrice = 100;
    }
    if (p == 2)
    {
        strcpy(n->productName, "BOLL");
        n->productPrice = 100;
    }
    if (p == 3)
    {
        strcpy(n->productName, "HELMET");
        n->productPrice = 1500;
    }
    if (p == 4)
    {
        strcpy(n->productName, "SHOES");
        n->productPrice = 2000;
    }
    if (p == 5)
    {
        strcpy(n->productName, "GLOVES");
        n->productPrice = 500;
    }

    n->productQuantity = q;
    n->productTotalBill = n->productPrice * n->productQuantity;
    n->next = NULL;

    struct node *ptr = head;

    if (head == NULL)
    {
        head = n;
    }
    else
    {
        while (ptr->next != NULL)
        {
            if (ptr->productPrice == n->productPrice)
            {
                ptr->productQuantity += n->productQuantity;
                ptr->productTotalBill = ptr->productPrice * ptr->productQuantity;
                free(n);
                return;
            }
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = n;
    }
}

void cancel(int cancelPro, int q)
{
    if (head == NULL)
    {
        printf("You have not purchased any product to cancel...");
        return;
    }

    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        if (ptr->productPrice == cancelPro)
        {
            ptr->productQuantity -= q;
            if (ptr->productQuantity < 0)
            {
                ptr->productQuantity = 0;
            }
            ptr->productTotalBill = ptr->productPrice * ptr->productQuantity;
            printf("Canceled %d quantities of %s. Now it costs %d\n", q, ptr->productName, ptr->productTotalBill);
            // Bill();
            return;
        }
        ptr = ptr->next;
    }
}

void Bill()
{
    int total = 0;

    if (head == NULL)
    {
        printf("Total Bill: 0\n");
        return;
    }

    struct node *ptr = head;
    printf("PRODUCT NAME  | QUANTITY | PRICE PER PRODUCT  | TOTAL PRICE\n");
    do
    {
        printf("%-13s | %-8d | %-18d | %d\n", ptr->productName, ptr->productQuantity, ptr->productPrice, ptr->productTotalBill);
        total += ptr->productTotalBill;
        ptr = ptr->next;
    } while (ptr != NULL);

    printf("------------------------------------------------------------\n");
    printf("Total Bill: %d\n", total);
}

int main()
{

    int ch1, ch2, cancelProduct;
    int quantity;

    printf("Super Shop....\n");
    do
    {
        printf("\nServices!!\n");
        printf("1. Add to Cart\n2. Delete Product\n3. Print Receipt\n4. Quit\nEnter the choice: ");
        scanf("%d", &ch1);

        switch (ch1)
        {
        case 1:
            printf("1. Cricket Bat    -  $1000\n2. Cricket Balls  -  $100\n3. Cricket Helmet -  $1500\n4. Cricket Shoes  -  $2000\n5. Cricket Gloves -  $500\nEnter the choice: ");
            scanf("%d", &ch2);
            printf("Enter the quantity: ");
            scanf("%d", &quantity);
            switch (ch2)
            {
            case 1:
                purchase(ch2, quantity);
                printf("%d quantities of Cricket Bat purchased.\nIt costs %d\n", quantity, 1000 * quantity);
                break;
            case 2:
                purchase(ch2, quantity);
                printf("%d quantities of Cricket Balls purchased.\nIt costs %d\n", quantity, 100 * quantity);
                break;
            case 3:
                purchase(ch2, quantity);
                printf("%d quantities of Cricket Helmet purchased.\nIt costs %d\n", quantity, 1500 * quantity);
                break;
            case 4:
                purchase(ch2, quantity);
                printf("%d quantities of Cricket Shoes purchased.\nIt costs %d\n", quantity, 2000 * quantity);
                break;
            case 5:
                purchase(ch2, quantity);
                printf("%d quantities of Cricket Gloves purchased.\nIt costs %d\n", quantity, 500 * quantity);
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 2:
            printf("Enter product code to cancel it: ");
            scanf("%d", &cancelProduct);
            printf("Quantities to be canceled: ");
            scanf("%d", &quantity);
            switch (cancelProduct)
            {
            case 1:
                cancelProduct = 1000;
                cancel(cancelProduct, quantity);
                break;
            case 2:
                cancelProduct = 100;
                cancel(cancelProduct, quantity);
                break;
            case 3:
                cancelProduct = 1500;
                cancel(cancelProduct, quantity);
                break;
            case 4:
                cancelProduct = 2000;
                cancel(cancelProduct, quantity);
                break;
            case 5:
                cancelProduct = 500;
                cancel(cancelProduct, quantity);
                break;
            default:
                printf("Invalid choice\n");
            }
            break;
        case 3:
            Bill();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (ch1 != 4);

    // Free memory allocated for nodes
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
