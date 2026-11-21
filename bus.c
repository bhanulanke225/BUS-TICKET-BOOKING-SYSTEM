#include <stdio.h>

int main()
{
    int choice, route, seats, id = 100;
    int booked = 0, i, j, cancelID, found;
    int fare;
    int price[] = {300, 450, 500};
    int available[] = {40, 40, 40};

    int bookingID[50], busRoute[50], ticketCount[50];
    int ages[50][10];
    char names[50][10][50];

    do
    {
        printf("\n===== BUS TICKET BOOKING =====\n");
        printf("1. View Routes\n");
        printf("2. Book Tickets\n");
        printf("3. View Booking Summary\n");
        printf("4. Cancel Booking\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\n1. Guntur - Vijayawada Rs.300\n");
                printf("2. Guntur - Hyderabad Rs.450\n");
                printf("3. Guntur - Chennai Rs.500\n");
                break;

            case 2:
                if(booked >= 50)
                {
                    printf("Booking limit reached!\n");
                    break;
                }

                printf("Select route (1-3): ");
                scanf("%d", &route);

                if(route < 1 || route > 3)
                {
                    printf("Invalid route!\n");
                    break;
                }

                printf("Total Tickets Available: %d\n",
                available[route-1]);

                printf("Enter number of tickets (1-10): ");
                scanf("%d", &seats);

                if(seats < 1 || seats > 10)
                {
                    printf("Invalid ticket count!\n");
                    break;
                }

                if(seats > available[route-1])
                {
                    printf("Not enough tickets available!\n");
                    break;
                }

                for(i = 0; i < seats; i++)
                {
                    printf("\nPassenger %d Name: ", i+1);
                    scanf(" %49[^\n]", names[booked][i]);

                    printf("Passenger %d Age: ", i+1);
                    scanf("%d", &ages[booked][i]);

                    if(ages[booked][i] < 1 ||
                       ages[booked][i] > 120)
                    {
                        printf("Invalid age!\n");
                        i--;
                    }
                }

                bookingID[booked] = id++;
                busRoute[booked] = route;
                ticketCount[booked] = seats;

                fare = price[route-1] * seats;
                available[route-1] -= seats;

                printf("\n===== BOOKING TICKET =====\n");
                printf("Booking ID: %d\n", bookingID[booked]);

                switch(route)
                {
                    case 1:
                        printf("Route: Guntur - Vijayawada\n");
                        break;
                    case 2:
                        printf("Route: Guntur - Hyderabad\n");
                        break;
                    case 3:
                        printf("Route: Guntur - Chennai\n");
                        break;
                }

                printf("No. of Tickets: %d\n", seats);
                printf("Total Price: Rs.%d\n", fare);

                printf("\nPassenger Details:\n");

                for(i = 0; i < seats; i++)
                {
                    printf("%d. %s - Age: %d\n",
                    i+1, names[booked][i], ages[booked][i]);
                }

                booked++;

                printf("Remaining Tickets: %d\n",
                available[route-1]);
                break;

            case 3:
                if(booked == 0)
                {
                    printf("No bookings available!\n");
                    break;
                }

                for(i = 0; i < booked; i++)
                {
                    if(bookingID[i] != -1)
                    {
                        printf("\n===== BOOKING SUMMARY =====\n");
                        printf("Booking ID: %d\n", bookingID[i]);

                        switch(busRoute[i])
                        {
                            case 1:
                                printf("Route: Guntur - Vijayawada\n");
                                break;
                            case 2:
                                printf("Route: Guntur - Hyderabad\n");
                                break;
                            case 3:
                                printf("Route: Guntur - Chennai\n");
                                break;
                        }

                        printf("No. of Tickets: %d\n",
                        ticketCount[i]);

                        printf("Total Price: Rs.%d\n",
                        price[busRoute[i]-1] * ticketCount[i]);

                        printf("\nPassenger Names and Ages:\n");

                        for(j = 0; j < ticketCount[i]; j++)
                        {
                            printf("Passenger %d\n", j+1);
                            printf("Name: %s\n", names[i][j]);
                            printf("Age: %d\n", ages[i][j]);
                        }
                    }
                }
                break;

            case 4:
                printf("Enter Booking ID: ");
                scanf("%d", &cancelID);

                found = 0;

                for(i = 0; i < booked; i++)
                {
                    if(bookingID[i] == cancelID)
                    {
                        available[busRoute[i]-1] += ticketCount[i];
                        bookingID[i] = -1;

                        printf("Booking Cancelled!\n");
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                    printf("Booking ID not found!\n");
                break;

            case 5:
                printf("Thank you for booking!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}
