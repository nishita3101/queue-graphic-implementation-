#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#define max 10
#define MAX 10
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

//-------------------------------------------------------------//
//output restricted double ended
int ordq[max];
int of_f, of_r;

void oinit() {
    of_f = -1;
    of_r = -1;
}

void oenqueue(int x) {
    if (of_r == max - 1) {
        printf("Queue overflow\n");
    } else {
        if (of_r == -1)
            of_r = of_f = 0;
        else {
            of_r++;
        }
        ordq[of_r] = x;
    }
}

void oenqueuef(int x) {
    if (of_f <= 0)
        printf("Cannot insert from front\n");
    else {
        of_f--;
        ordq[of_f] = x;
    }
}

int odequeue() {
    int x = -1;
    if (of_f == -1) {
        printf("Underflow\n");
    } else {
        x = ordq[of_f];
        if (of_r == of_f)
            of_r = of_f = -1;
        else
            of_f++;
        printf("%d deleted from queue\n", x);
    }
    return x;
}

void odisplay() {
    if (of_f == -1)
        printf("Queue underflow\n");
    else {
        printf("Queue elements:\n");
        for (int i = of_f; i <= of_r; i++)
            printf("%d ", ordq[i]);
        printf("\n");
    }
}

int ounderflow() {
    return (of_f == -1);
}

int ooverflow() {
    return (of_r == max - 1);
}

int osize() {
    if (of_f == -1)
        return 0;
    else
        return (of_r - of_f + 1);
}

void drawArrow(int x, int y) {
    line(x, y, x, y + 10);
    line(x, y + 10, x - 5, y + 5);
    line(x, y + 10, x + 5, y + 5);
}

void odrawQueue() {
    cleardevice();
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(180, 40, "QUEUE VISUALIZATION");

    int startX = 100;
    int startY = 200;
    int boxWidth = 60;
    int boxHeight = 50;
    char str[10];

    
    for (int i = 0; i < MAX; i++) {
        rectangle(startX + i * (boxWidth + 5), startY,
                  startX + i * (boxWidth + 5) + boxWidth,
                  startY + boxHeight);
    }
    if (of_f != -1) {
        for (int i = of_f; i <= of_r; i++) {
            sprintf(str, "%d", ordq[i]);
            outtextxy(startX + i * (boxWidth + 5) + 20,
                      startY + 15, str);
        }
    }
    if (of_f != -1) {
        int fx = startX + of_f * (boxWidth + 5) + boxWidth / 2;
        int fy = startY - 30;
        sprintf(str, "F=%d", of_f);
        outtextxy(fx - 15, fy - 20, str);
        drawArrow(fx, fy - 5); 
    }
    if (of_r != -1) {
        int rx = startX + of_r * (boxWidth + 5) + boxWidth / 2;
        int ry = startY + boxHeight + 30;
        sprintf(str, "R=%d", of_r);
        outtextxy(rx - 15, ry + 10, str);
        line(rx, ry, rx, ry - 10);
        line(rx, ry - 10, rx - 5, ry - 5);
        line(rx, ry - 10, rx + 5, ry - 5);
    }
}
void learndeorQueue() {
    int next = 1; 

    printf("\n================ OUTPUT RESTRICTED DEQUE =================\n");
    printf("A DEQUE (Double Ended Queue) is a linear data structure in which\n");
    printf("elements can be inserted and deleted from BOTH ends: FRONT and REAR.\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nHowever, in an OUTPUT RESTRICTED DEQUE:\n");
    printf("- INSERTION is allowed at BOTH ends (FRONT and REAR).\n");
    printf("- DELETION is allowed from ONLY ONE END (usually FRONT).\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nSo the operations are:\n");
    printf("-----------------------------------------------------------\n");
    printf("Operation\tAllowed At\n");
    printf("-----------------------------------------------------------\n");
    printf("Insert\t\tFRONT \n");
    printf("Insert\t\tREAR \n");
    printf("Delete\t\tFRONT\n");
    printf("Delete\t\tREAR  (NOT allowed)\n");
    printf("-----------------------------------------------------------\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nWhy is it called 'OUTPUT Restricted'?\n");
    printf("- Because the DELETE operation (output) is RESTRICTED to only one end.\n");
    printf("- But INSERT operations can happen from both ends.\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nReal-World Uses:\n");
    printf("- Systems where data may arrive from both ends, but processing/removal\n");
    printf("  always happens in a single direction (like a print queue).\n");
    printf("- Algorithms requiring flexible insertion but fixed removal direction\n");
    printf("- Task scheduling systems\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nIn short:\n");
    printf(" Insertion allowed at BOTH ends but insertion from front can only be done when front is greater than 0\n");
    printf(" Deletion allowed at only ONE end\n");
    printf("============================================================\n");
}


void dequeueormain() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    oinit();

    int ch, x, y,choice;
    of_f = -1;
    of_r = -1;
    do {
        printf("\n========= MAIN MENU =========\n");
        printf("1. Learn about Output Restricted Double Ended Queue\n");
        printf("2. Output Restricted Double Ended Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            learndeorQueue();
            break;

        case 2:
        {


    do {
        odrawQueue(); 
        printf("\nMENU\n");
        printf("1. Initialization\n");
        printf("2. Enqueue from rear\n");
        printf("3. Enqueue from front\n");
        printf("4. Dequeue\n");
        printf("5. Display\n");
        printf("6. Size\n");
        printf("7. Underflow check\n");
        printf("8. Overflow check\n");
        printf("9. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            oinit();
            break;
        case 2:
            printf("Enter element to enqueue (rear): ");
            scanf("%d", &x);
            oenqueue(x);
            break;
        case 3:
            printf("Enter element to enqueue (front): ");
            scanf("%d", &x);
            oenqueuef(x);
            break;
        case 4:
            odequeue();
            break;
        case 5:
            odisplay();
            break;
        case 6:
            y = osize();
            printf("Size: %d\n", y);
            break;
        case 7:
            if (ounderflow())
                printf("Queue underflow\n");
            else
                printf("Not underflow\n");
            break;
        case 8:
            if (ooverflow())
                printf("Queue overflow\n");
            else
                printf("Not overflow\n");
            break;
        case 9:
            closegraph();
            printf("Exiting program...\n");
            return ;
        default:
            printf("Invalid choice!\n");
        }
    }while (ch != 9);
}
break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);



    closegraph();
    return ;
}

//-------------------------------------------------------------------------//
//input restricted double ended 
int irdq[max];
int ir_f, ir_r;
void iinit() {
    ir_f = -1;
    ir_r = -1;
}
void ienqueue(int x) {
    if (ir_r == max - 1) {
        printf("Queue overflow\n");
    } else {
        if (ir_r == -1)
            ir_r = ir_f = 0;
        else
            ir_r++;
        irdq[ir_r] = x;
    }
}

void idequeuer() {
    int x;
    if (ir_r == -1) {
        printf("Underflow\n");
    } else {
        x = irdq[ir_r];
        if (ir_r == ir_f)
            ir_r = ir_f = -1;
        else
            ir_r--;
        printf("%d deleted from rear\n", x);
    }
}

void idequeue() {
    int x;
    if (ir_f == -1) {
        printf("Underflow\n");
    } else {
        x = irdq[ir_f];
        if (ir_r == ir_f)
            ir_r = ir_f = -1;
        else
            ir_f++;
        printf("%d deleted from front\n", x);
    }
}

void idisplay() {
    if (ir_f == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements:\n");
        for (int i = ir_f; i <= ir_r; i++)
            printf("%d ", irdq[i]);
        printf("\n");
    }
}

int iunderflow() {
    return (ir_f == -1);
}

int ioverflow() {
    return (ir_r == max - 1);
}

int isize() {
    if (ir_f == -1)
        return 0;
    else
        return (ir_r - ir_f + 1);
}

void drawArrowDown(int x, int y) {
    line(x, y, x, y + 10);
    line(x, y + 10, x - 5, y + 5);
    line(x, y + 10, x + 5, y + 5);
}

void drawArrowUp(int x, int y) {
    line(x, y, x, y - 10);
    line(x, y - 10, x - 5, y - 5);
    line(x, y - 10, x + 5, y - 5);
}

void idrawQueue() {
    cleardevice();

    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(180, 40, "DOUBLE ENDED QUEUE VISUALIZATION");

    int startX = 100;
    int startY = 200;
    int boxWidth = 60;
    int boxHeight = 50;
    char str[10];
    for (int i = 0; i < max; i++) {
        rectangle(startX + i * (boxWidth + 5), startY,
                  startX + i * (boxWidth + 5) + boxWidth,
                  startY + boxHeight);
    }
    if (ir_f != -1) {
        for (int i = ir_f; i <= ir_r; i++) {
            sprintf(str, "%d", irdq[i]);
            outtextxy(startX + i * (boxWidth + 5) + 20,
                      startY + 15, str);
        }
    }
    if (ir_f != -1) {
        int fx = startX + ir_f * (boxWidth + 5) + boxWidth / 2;
        int fy = startY - 30;
        sprintf(str, "F=%d", ir_f);
        outtextxy(fx - 15, fy - 20, str);
        drawArrowDown(fx, fy - 5);
    }
    if (ir_r != -1) {
        int rx = startX + ir_r * (boxWidth + 5) + boxWidth / 2;
        int ry = startY + boxHeight + 30;
        sprintf(str, "R=%d", ir_r);
        outtextxy(rx - 15, ry + 10, str);
        drawArrowUp(rx, ry);
    }
}
void learndeirQueue() {
    int next = 1;  

    printf("\n================ INPUT RESTRICTED DEQUE =================\n");
    printf("A DEQUE (Double Ended Queue) is a linear data structure in which\n");
    printf("insertion and deletion can take place from BOTH ends (front and rear).\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nHowever, in an INPUT RESTRICTED DEQUE:\n");
    printf("- Insertion is allowed only at ONE END (usually REAR).\n");
    printf("- Deletion is allowed from BOTH ENDS (FRONT and REAR).\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nSo the operations are:\n");
    printf("---------------------------------------------------------\n");
    printf("Operation\tAllowed At\n");
    printf("---------------------------------------------------------\n");
    printf("Insert\t\tREAR only \n");
    printf("Delete\t\tFRONT \n");
    printf("Delete\t\tREAR \n");
    printf("---------------------------------------------------------\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nWhy is it called 'INPUT Restricted'?\n");
    printf("- Because the INSERT operation (input) is RESTRICTED to one side only.\n");
    printf("- But OUTPUT operations (deletions) can happen from both sides.\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nReal-World Uses:\n");
    printf("- Job or task queues where insertion is fixed at one point,\n");
    printf("  but processing/removal can happen from either side.\n");
    printf("- Keyboard buffer systems\n");
    printf("- Undo/Redo operations in applications\n\n");

    printf("Press 1 to continue or 0 to skip: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nIn short:\n");
    printf("Deletion allowed at BOTH ends\n");
    printf("Insertion allowed at only ONE end\n");
    printf("==========================================================\n");
}


void dequeueirmain() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    iinit();

    int ch, x, y,choice;
     ir_f = -1;
    ir_r = -1;
    do {
        printf("\n========= MAIN MENU =========\n");
        printf("1. Learn about Double ended input restricted Queue\n");
        printf("2. double ended Queue(input restricted) Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            learndeirQueue();
            break;

        case 2:
        {

    do{
        idrawQueue(); 

        printf("\nMENU\n");
        printf("1. Initialization\n");
        printf("2. Enqueue (rear)\n");
        printf("3. Dequeue from front\n");
        printf("4. Dequeue from rear\n");
        printf("5. Display\n");
        printf("6. Size\n");
        printf("7. Underflow check\n");
        printf("8. Overflow check\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            iinit();
            break;
        case 2:
            printf("Enter element to enqueue: ");
            scanf("%d", &x);
            ienqueue(x);
            break;
        case 3:
            idequeue();
            break;
        case 4:
            idequeuer();
            break;
        case 5:
            idisplay();
            break;
        case 6:
            y = isize();
            printf("Number of elements: %d\n", y);
            break;
        case 7:
            if (iunderflow())
                printf("Queue underflow\n");
            else
                printf("Not underflow\n");
            break;
        case 8:
            if (ioverflow())
                printf("Queue overflow\n");
            else
                printf("Not overflow\n");
            break;
        case 9:
            closegraph();
            printf("Exiting program...\n");
            return ;
        default:
            printf("Invalid choice\n");
        }
    }while (ch != 9);
}
break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);



    closegraph();
    return ;
}

//-------------------------------------------------------------------------//
//circular
struct cq {
    int arr[MAX];
    int front;
    int rear;
};

void init(struct cq *q) {
    q->front = -1;
    q->rear = -1;
}

int underflow(struct cq *q) {
    return (q->front == -1);
}

int overflow(struct cq *q) {
    return ((q->rear + 1) % MAX == q->front);
}

void enqueue(struct cq *q, int value) {
    if (overflow(q)) {
        printf("Queue is full\n");
        return;
    }
    if (underflow(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX;
    }
    q->arr[q->rear] = value;
    printf("%d inserted in queue\n", value);
}

void dequeue(struct cq *q) {
    if (underflow(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("%d deleted from queue\n", q->arr[q->front]);
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX;
    }
}

int size(struct cq *q) {
    if (underflow(q)) return 0;
    if (q->rear >= q->front) return q->rear - q->front + 1;
    return MAX - (q->front - q->rear - 1);
}

void display(struct cq *q) {
    if (underflow(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = q->front;
    while (1) {
        printf("%d ", q->arr[i]);
        if (i == q->rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void drawQueue(struct cq *q) {
    cleardevice();
    setbkcolor(WHITE);
    setcolor(BLACK);

    int cx = 320, cy = 240;
    int outerR = 150, innerR = 100;

    circle(cx, cy, outerR);
    circle(cx, cy, innerR);

    for (int i = 0; i < MAX; ++i) {
        double angle = (2.0 * M_PI / MAX) * i;
        int x1 = cx + (int)(outerR * cos(angle));
        int y1 = cy + (int)(outerR * sin(angle));
        int x2 = cx + (int)(innerR * cos(angle));
        int y2 = cy + (int)(innerR * sin(angle));
        line(x1, y1, x2, y2);
    }

    settextstyle(BOLD_FONT, 0, 3);
    outtextxy(160, 50, (char*)"CIRCULAR QUEUE VISUALIZATION");

    if (!underflow(q)) {
        int i = q->front;
        while (1) {
            double angleMid = (2.0 * M_PI / MAX) * (i + 0.5);
            int tx = cx + (int)((innerR + 25) * cos(angleMid));
            int ty = cy + (int)((innerR + 25) * sin(angleMid));
            char buf[16];
            sprintf(buf, "%d", q->arr[i]);
            outtextxy(tx - textwidth(buf)/2, ty - textheight(buf)/2, buf);

            if (q->front == q->rear && i == q->front) {
                int fx = cx + (int)((outerR + 30) * cos(angleMid)) - 12;
                int fy = cy + (int)((outerR + 30) * sin(angleMid));
                int rx = fx + 24;
                int ry = fy;
                outtextxy(fx - textwidth("F")/2, fy - textheight("F")/2, "F");
                outtextxy(rx - textwidth("R")/2, ry - textheight("R")/2, "R");
            } else {
                if (i == q->front) {
                    int fx = cx + (int)((outerR + 30) * cos(angleMid));
                    int fy = cy + (int)((outerR + 30) * sin(angleMid));
                    outtextxy(fx - textwidth("F")/2, fy - textheight("F")/2, "F");
                }
                if (i == q->rear) {
                    int rx = cx + (int)((outerR + 30) * cos(angleMid));
                    int ry = cy + (int)((outerR + 30) * sin(angleMid));
                    outtextxy(rx - textwidth("R")/2, ry - textheight("R")/2, "R");
                }
            }

            if (i == q->rear) break;
            i = (i + 1) % MAX;
        }
    }

    char pos[60];
    sprintf(pos, "Front = %d    Rear = %d", q->front, q->rear);
    settextstyle(BOLD_FONT, 0, 1);
    outtextxy(220, 420, pos);
}

void showTextBox(const char *title, const char *desc) {
    cleardevice();
    setbkcolor(WHITE);
    setcolor(BLUE);
    settextstyle(BOLD_FONT, 0, 3);
    outtextxy(100, 80, (char*)title);

    setcolor(BLACK);
    settextstyle(DEFAULT_FONT, 0, 2); 
    int y = 160;
    char temp[500];
    int i = 0, j = 0;

    while (desc[i] != '\0') {
        if (desc[i] == '\n' || j == 65) {
            temp[j] = '\0';
            outtextxy(60, y, (char*)temp);
            y += 30;
            j = 0;
        } else {
            temp[j++] = desc[i];
        }
        i++;
    }
    temp[j] = '\0';
    outtextxy(60, y, (char*)temp);

    setcolor(RED);
    outtextxy(100, 440, (char*)"Press any key to go back...");
    getch();
}

void learnMode() {
    int key = 0;
    while (1) {
        cleardevice();
        setbkcolor(WHITE);
        setcolor(BLACK);
        settextstyle(BOLD_FONT, 0, 3);
        outtextxy(130, 80, (char*)"LEARN MODE - CIRCULAR QUEUE");
        settextstyle(DEFAULT_FONT, 0, 2);
        outtextxy(100, 150, (char*)"1. Learn about Circular Queue (Concept)");
        outtextxy(100, 190, (char*)"2. Learn about Operations");
        outtextxy(100, 230, (char*)"3. Exit Learn Mode");
        outtextxy(100, 290, (char*)"Press 1, 2, or 3 to choose...");

        key = getch();
        if (key == '1') {
            showTextBox(
                "What is a Circular Queue?",
                "A Circular Queue is an advanced form of a Linear Queue.\n"
                "It connects the end of the queue back to the front, forming a circle.\n"
                "When the rear reaches the end, it wraps around to the start if space is available.\n"
                "This avoids the wastage of space that occurs in Linear Queues.\n"
                "It is implemented using modulo arithmetic."
            );
        } else if (key == '2') {
            showTextBox(
                "Circular Queue Operations",
                "1. Enqueue - Insert an element at the rear ((rear+1)%MAX).\n"
                "2. Dequeue - Remove an element from the front ((front+1)%MAX).\n"
                "3. Overflow - When the next rear == front.\n"
                "4. Underflow - When queue is empty (front == -1).\n"
                "5. Display - Show all elements in circular order."
            );
        } else if (key == '3' || key == 27) {
            break;
        }
    }
}

void circularmain() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    struct cq q;
    init(&q);

    int mainChoice, choice, value;

    while (1) {
        cleardevice();
        printf("\n========= MAIN MENU =========\n");
        printf("1. Learn Mode\n");
        printf("2. Perform Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        if (mainChoice == 1) {
            learnMode();
        } 
        else if (mainChoice == 2) {
            do {
                drawQueue(&q);
                printf("\n------ Circular Queue Operations ------\n");
                printf("0. Initialize queue\n");
                printf("1. Check Underflow\n");
                printf("2. Check Overflow\n");
                printf("3. Enqueue\n");
                printf("4. Dequeue\n");
                printf("5. Display\n");
                printf("6. Size\n");
                printf("7. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 0: init(&q); printf("Queue reinitialized.\n"); break;
                    case 1: if (underflow(&q)) printf("Queue is empty\n");
                            else printf("Queue is not empty\n"); break;
                    case 2: if (overflow(&q)) printf("Queue is full\n");
                            else printf("Queue is not full\n"); break;
                    case 3: printf("Enter value: "); scanf("%d", &value);
                            enqueue(&q, value); break;
                    case 4: dequeue(&q); break;
                    case 5: display(&q); break;
                    case 6: printf("Size = %d\n", size(&q)); break;
                    case 7: break;
                    default: printf("Invalid choice\n");
                }
            } while (choice != 7);
        } 
        else if (mainChoice == 3) {
            closegraph();
            printf("Exiting program...\n");
            return ;
        } 
        else {
            printf("Invalid choice\n");
        }
    }

    closegraph();
    return ;
}
//-----------------------------------------------------------------------------//
//priority
int prq[2][max];
int pr_f, pr_r;

void prinit() { pr_f = -1; pr_r = -1; }

void arrange() {
    int i, j, t;
    for (i = pr_f; i <= pr_r; i++) {
        for (j = i + 1; j <= pr_r; j++) {
            if (prq[1][i] > prq[1][j]) {
                t = prq[1][i];
                prq[1][i] = prq[1][j];
                prq[1][j] = t;
                t = prq[0][i];
                prq[0][i] = prq[0][j];
                prq[0][j] = t;
            }
        }
    }
}

void prenqueue(int x, int y) {
    if (pr_r == max - 1)
        printf("Queue overflow\n");
    else {
        if (pr_r == -1)
            pr_r = pr_f = 0;
        else
            pr_r++;
        prq[0][pr_r] = x;
        prq[1][pr_r] = y;
    }
}

int prdequeue() {
    int x, y;
    if (pr_f == -1)
        printf("Underflow\n");
    else {
        x = prq[0][pr_f];
        y = prq[1][pr_f];
        if (pr_r == pr_f)
            pr_r = pr_f = -1;
        else
            pr_f++;
        printf("%d deleted from priority queue\n", x);
    }
    return 0;
}

void prdisplay() {
    int i;
    if (pr_f == -1)
        printf("Underflow\n");
    else {
        printf("Queue elements (Element | Priority):\n");
        for (i = pr_f; i <= pr_r; i++)
            printf("%d | %d\n", prq[0][i], prq[1][i]);
    }
}

int prunderflow() { return (pr_f == -1); }
int proverflow() { return (pr_r == max - 1); }
int prsize() { return (pr_f == -1) ? 0 : (pr_r - pr_f + 1); }

void prdrawQueue() {
    cleardevice();
    setbkcolor(WHITE);   
    setcolor(BLACK);

    int startX = 180, startY = 180;
    int boxWidth = 80, boxHeight = 90;

    
    settextstyle(BOLD_FONT, 0, 3);
    outtextxy(120, 70, "PRIORITY QUEUE VISUALIZATION");

    
    int refX1 = 50, refY1 = 180;
    int refX2 = refX1 + boxWidth, refY2 = refY1 + boxHeight;
    rectangle(refX1, refY1, refX2, refY2);
    line(refX1, refY1 + boxHeight / 2, refX2, refY1 + boxHeight / 2);

    settextstyle(BOLD_FONT, 0, 2);
    outtextxy(refX1 + 12, refY1 + 15, "DATA");
    outtextxy(refX1 + 2, refY1 + boxHeight / 2 + 15, "PRIORITY");

    
    if (pr_f != -1) {
        for (int i = pr_f; i <= pr_r; i++) {
            int x1 = startX + (i - pr_f) * (boxWidth + 15);
            int y1 = startY;
            int x2 = x1 + boxWidth;
            int y2 = y1 + boxHeight;

            rectangle(x1, y1, x2, y2);
            line(x1, y1 + boxHeight / 2, x2, y1 + boxHeight / 2);

            
            settextstyle(BOLD_FONT, 0, 2);

            char val[10], pri[10];
            sprintf(val, "%d", prq[0][i]);
            sprintf(pri, "%d", prq[1][i]);

            outtextxy(x1 + 25, y1 + 15, val);
            outtextxy(x1 + 25, y1 + boxHeight / 2 + 15, pri);

            
            settextstyle(DEFAULT_FONT, 0, 1);
            if (i == pr_f)
                outtextxy(x1 + 25, y2 + 10, "F");
            if (i == pr_r)
                outtextxy(x1 + 25, y2 + 25, "R");
        }
    }

    
    settextstyle(BOLD_FONT, 0, 1);
    char pos[60];
    sprintf(pos, "Front = %d    Rear = %d", pr_f, pr_r);
    outtextxy(240, 410, pos);
}
void learnPriorityQueue() {
    int next = 1; 

    printf("\n================= PRIORITY QUEUE =================\n");
    printf("A Priority Queue is a special type of Queue in which each element\n");
    printf("is assigned a PRIORITY value. The processing of elements depends\n");
    printf("on their priority, not just on the order in which they arrive.\n\n");

    printf("Press 1 to continue or 0 to stop: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nIn a normal Queue:\n");
    printf("- Elements are inserted at the REAR (back).\n");
    printf("- Elements are removed from the FRONT.\n");
    printf("- It follows the FIFO rule (First In, First Out).\n\n");

    printf("Press 1 to continue or 0 to stop: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nIn a Priority Queue:\n");
    printf("- Each element has a PRIORITY associated with it.\n");
    printf("- The element with the HIGHEST PRIORITY is served first.\n");
    printf("- If two elements have the same priority, they follow FIFO order.\n\n");

    printf("Press 1 to continue or 0 to stop: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nFor example:\n");
    printf("Let the elements be:\n");
    printf("A (priority 2),  B (priority 1),  C (priority 3)\n\n");
    printf("The order of removal will be:\n");
    printf("C → A → B   (because 3 > 2 > 1)\n\n");

    printf("Press 1 to continue or 0 to stop: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nFRONT and REAR in a Priority Queue:\n");
    printf("- FRONT points to the element that will be removed next\n");
    printf("  (the element with the highest priority).\n");
    printf("- REAR points to the position where the next new element\n");
    printf("  will be inserted.\n\n");

    printf("Press 1 to continue or 0 to stop: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nImplementation methods:\n");
    printf("- Using Arrays (simple but less flexible)\n");
    printf("- Using Linked Lists (dynamic in size)\n");
    printf("- Using Heaps (efficient for large data)\n\n");

    printf("Press 1 to continue or 0 to stop: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nCommon Applications:\n");
    printf("- CPU Process Scheduling (higher priority tasks execute first)\n");
    printf("- Dijkstra’s Shortest Path Algorithm\n");
    printf("- Operating System task management\n");
    printf("- Network packet routing and bandwidth management\n\n");

    printf("Press 1 to continue or 0 to stop: ");
    scanf("%d", &next);
    if (next != 1) return;


    printf("\nIn short, a Priority Queue ensures that IMPORTANT tasks are handled\n");
    printf("before less important ones, making it a powerful concept in computing.\n");
    printf("=================================================\n");
}



void prioritymain() {
    int ch, x, y,choice;
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    pr_f = -1;
    pr_r = -1;
    do {
        printf("\n========= MAIN MENU =========\n");
        printf("1. Learn about Priority Queue\n");
        printf("2. Priority Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            learnPriorityQueue();
            break;

        case 2:
        {


    do {
        cleardevice();
        prdrawQueue();

        printf("\nMENU\n");
        printf("1. Initialization\n2. Enqueue\n3. Dequeue\n4. Display\n5. Size\n6. Underflow\n7. Overflow\n8. Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
        case 1:
            prinit();
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &x);
            printf("Enter priority: ");
            scanf("%d", &y);
            prenqueue(x, y);
            arrange();
            break;
        case 3:
            prdequeue();
            break;
        case 4:
            prdisplay();
            break;
        case 5:
            y = prsize();
            printf("Size = %d\n", y);
            break;
        case 6:
            y = prunderflow();
            if (y)
                printf("Underflow\n");
            else
                printf("Not underflow\n");
            break;
        case 7:
            y = proverflow();
            if (y)
                printf("Overflow\n");
            else
                printf("Not overflow\n");
            break;
        case 8:
            printf("Exiting...\n");
            closegraph();
            return ;
        default:
            printf("Invalid choice\n");
        }
    } while (ch != 8);
}
break;

        case 3:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);



    closegraph();
    return ;
}
//------------------------------------------------------------------------//
//linear
int lq[max];
int l_f, l_r;

void linit() { l_f = -1; l_r = -1; }

void lenqueue(int x) {
    if (l_r == max - 1)
        printf("Queue overflow\n");
    else {
        if (l_r == -1)
            l_f = l_r = 0;
        else
            l_r++;
        lq[l_r] = x;
        printf("%d inserted into queue\n", x);
    }
}

int ldequeue() {
    if (l_f == -1) {
        printf("Queue underflow\n");
        return -1;
    } else {
        int x = lq[l_f];
        if (l_f == l_r)
            l_f = l_r = -1;
        else
            l_f++;
        printf("%d deleted from queue\n", x);
        return x;
    }
}

void ldisplay() {
    if (l_f == -1)
        printf("Queue is empty\n");
    else {
        printf("Queue elements: ");
        for (int i = l_f; i <= l_r; i++)
            printf("%d ", lq[i]);
        printf("\n");
    }
}

int lunderflow() { return (l_f == -1); }
int loverflow() { return (l_r == max - 1); }
int lsize() { return (l_f == -1) ? 0 : (l_r - l_f + 1); }


void ldrawQueue() {
    cleardevice();
    setbkcolor(WHITE);
    setcolor(BLACK);

    int startX = 100, startY = 200;
    int boxWidth = 80, boxHeight = 80;

    settextstyle(BOLD_FONT, 0, 3);
    outtextxy(150, 70, (char*)"LINEAR QUEUE VISUALIZATION");

    
    settextstyle(BOLD_FONT, 0, 2);
    for (int i = 0; i < max; i++) {
        int x1 = startX + i * (boxWidth + 10);
        int y1 = startY;
        int x2 = x1 + boxWidth;
        int y2 = y1 + boxHeight;
        rectangle(x1, y1, x2, y2);

        if (l_f != -1 && i >= l_f && i <= l_r) {
            char val[10];
            sprintf(val, "%d", lq[i]);
            outtextxy(x1 + 30, y1 + 25, val);
        }
    }

    settextstyle(DEFAULT_FONT, 0, 1);
    if (l_f != -1) {
        int fx = startX + l_f * (boxWidth + 10);
        int fy = startY + boxHeight + 10;
        outtextxy(fx + 30, fy, (char*)"F");
    }
    if (l_r != -1) {
        int rx = startX + l_r * (boxWidth + 10);
        int ry = startY + boxHeight + 25;
        outtextxy(rx + 30, ry, (char*)"R");
    }

    settextstyle(BOLD_FONT, 0, 1);
    char pos[60];
    sprintf(pos, "Front = %d    Rear = %d", l_f, l_r);
    outtextxy(250, 380, pos);
}

void lshowTextBox(const char *title, const char *desc) {
    cleardevice();
    setbkcolor(WHITE);
    setcolor(BLUE);
    settextstyle(BOLD_FONT, 0, 3);
    outtextxy(100, 80, (char*)title);

    setcolor(BLACK);
    settextstyle(DEFAULT_FONT, 0, 2); 
    int y = 160;
    char temp[500];
    int i = 0, j = 0;

    while (desc[i] != '\0') {
        if (desc[i] == '\n' || j == 60) {
            temp[j] = '\0';
            outtextxy(60, y, (char*)temp);
            y += 35;
            j = 0;
        } else {
            temp[j++] = desc[i];
        }
        i++;
    }
    temp[j] = '\0';
    outtextxy(60, y, (char*)temp);

    setcolor(RED);
    outtextxy(100, 440, (char*)"Press any key to go back...");
    getch();
}

void llearnMode() {
    int key = 0;
    while (1) {
        cleardevice();
        setbkcolor(WHITE);
        setcolor(BLACK);
        settextstyle(BOLD_FONT, 0, 3);
        outtextxy(130, 80, (char*)"LEARN MODE - LINEAR QUEUE");
        settextstyle(DEFAULT_FONT, 0, 2);
        outtextxy(100, 150, (char*)"1. Learn about Linear Queue (Concept)");
        outtextxy(100, 190, (char*)"2. Learn about Operations");
        outtextxy(100, 230, (char*)"3. Exit Learn Mode");
        outtextxy(100, 290, (char*)"Press 1, 2, or 3 to choose...");

        key = getch();
        if (key == '1') {
            lshowTextBox(
                "What is a Linear Queue?",
                "A Linear Queue is a data structure that follows FIFO (First In First Out).\n"
                "The element inserted first is the first one to be removed.\n"
                "It has two ends:\n"
                "Front - where elements are deleted.\n"
                "Rear  - where elements are inserted.\n"
                "It is used in job scheduling, printers, and CPU task management."
            );
        } else if (key == '2') {
            lshowTextBox(
                "Queue Operations",
                "1. Enqueue - Insert element at the rear end.\n"
                "2. Dequeue - Delete element from the front end.\n"
                "3. Display - Show all elements in order.\n"
                "4. Underflow - Queue is empty.\n"
                "5. Overflow - Queue is full.\n"
                "6. Size - Shows total elements present."
            );
        } else if (key == '3' || key == 27)
            break;
    }
}

void linearmain() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    linit();

    int mainChoice, choice, x;

    while (1) {
        cleardevice();
        printf("\n========= MAIN MENU =========\n");
        printf("1. Learn Mode\n");
        printf("2. Perform Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &mainChoice);

        if (mainChoice == 1) {
            llearnMode();
        }
        else if (mainChoice == 2) {
            do {
                ldrawQueue();
                printf("\n------ Linear Queue Operations ------\n");
                printf("1. Initialize\n2. Enqueue\n3. Dequeue\n4. Display\n5. Size\n6. Underflow\n7. Overflow\n8. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &choice);

                switch (choice) {
                    case 1: linit(); break;
                    case 2: printf("Enter element: "); scanf("%d", &x); lenqueue(x); break;
                    case 3: ldequeue(); break;
                    case 4: ldisplay(); break;
                    case 5: printf("Size = %d\n", lsize()); break;
                    case 6: if (lunderflow()) printf("Queue underflow\n"); else printf("Not underflow\n"); break;
                    case 7: if (loverflow()) printf("Queue overflow\n"); else printf("Not overflow\n"); break;
                    case 8: break;
                    default: printf("Invalid choice\n");
                }
            } while (choice != 8);
        }
        else if (mainChoice == 3) {
            closegraph();
            printf("Exiting program...\n");
            return ;
        }
        else {
            printf("Invalid choice\n");
        }
    }
}


int main() {
    int choice, subchoice;
    int next = 1;  

    while (1) {
        system("cls"); 
        printf("=====================================\n");
        printf("        QUEUE EXPLORATION MODE        \n");
        printf("=====================================\n");
        printf("Welcome! Today we will be learning about QUEUES -one of the most\n");
        printf("important data structures used in real-world applications.\n\n");
        printf("Would you like to start with the learning section?\n");
        printf("1. Yes, teach me what a Queue is\n");
        printf("2. No, take me directly to the main menu\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 2) {
        goto MENU;  
        }
        printf("What is a Queue?\n");
        printf("A Queue is a linear data structure that stores elements in a\n");
        printf("sequential manner, following the rule of First In, First Out (FIFO).\n");
        printf("This means the element added first will be removed first, just like\n");
        printf("a line of people waiting at a ticket counter - the first person gets\n");
        printf("the ticket first, and the last person has to wait.\n\n");

        printf("Press 1 to continue or 0 to skip: ");
        scanf("%d", &next);
        if (next != 1) goto MENU;   

        printf("\nBasic Concept:\n");
        printf("Imagine you are standing in a queue for movie tickets.\n");
        printf("You stand at the end (rear) of the line when you arrive.\n");
        printf("The person at the front of the line is the one who gets served first.\n");
        printf("This is exactly how a queue works in programming!\n\n");

        printf("Press 1 to continue or 0 to skip: ");
        scanf("%d", &next);
        if (next != 1) goto MENU;

        printf("\nImportant Terms:\n");
        printf("Front: Represents the position of the first element in the queue.\n");
        printf("       -> Deletion (removal) always happens from the front.\n");
        printf("       -> You can think of it as the first person in line.\n");
        printf("Rear : Represents the position of the last element in the queue.\n");
        printf("       -> Insertion (adding a new element) always happens at the rear.\n");
        printf("       -> Like the last person joining the queue.\n\n");

        printf("Press 1 to continue or 0 to skip: ");
        scanf("%d", &next);
        if (next != 1) goto MENU;

        printf("\nReal-Life Examples:\n");
        printf("- People standing in a line for bus tickets.\n");
        printf("- Tasks waiting in a printer's job queue.\n");
        printf("- CPU process scheduling (where processes wait their turn).\n");
        printf("- Call center waiting systems.\n\n");

        printf("Press 1 to continue or 0 to skip: ");
        scanf("%d", &next);
        if (next != 1) goto MENU;

        printf("\nMain Operations of Queue:\n");
        printf("- Enqueue : Add an element to the queue (at the rear).\n");
        printf("- Dequeue : Remove an element from the queue (from the front).\n");
        printf("- Size    : Get the number of elements in the queue.\n");
        printf("- Display : Show the elements in the queue.\n");
        printf("- Underflow : Check if the queue is empty.\n");
        printf("- Overflow  : Check if the queue is full (in case of fixed size queue).\n\n");

        printf("Press 1 to continue or 0 to skip: ");
        scanf("%d", &next);
        if (next != 1) goto MENU;

        printf("\nTypes of Queues:\n");
        printf("1. Linear Queue   - Simple queue following FIFO rule.\n");
        printf("2. Circular Queue -The last position connects back to the first to reuse space.\n");
        printf("3. Priority Queue -Each element has a priority; higher priority elements are served first.\n");
        printf("4.Double-Ended Queue (Deque) - Elements can be inserted or removed from both ends.\n\n");

MENU:   

        printf("=====================================\n");
        printf("           QUEUE MAIN MENU           \n");
        printf("=====================================\n");
        printf("1. Linear Queue\n");
        printf("2. Circular Queue\n");
        printf("3. Priority Queue\n");
        printf("4. Double Ended Queue\n");
        printf("0. Exit\n");
        printf("-------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: linearmain(); break;
            case 2: circularmain(); break;
            case 3: prioritymain(); break;
            case 4:
                while (1) {
                    system("cls");
                    printf("=====================================\n");
                    printf("       DOUBLE ENDED QUEUE MENU       \n");
                    printf("=====================================\n");
                    printf("1. Input Restricted Deque\n");
                    printf("2. Output Restricted Deque\n");
                    printf("0. Back to Main Menu\n");
                    printf("-------------------------------------\n");
                    printf("Enter your choice: ");
                    scanf("%d", &subchoice);

                    if (subchoice == 1) dequeueirmain();
                    else if (subchoice == 2) dequeueormain();
                    else if (subchoice == 0) break;
                    else {
                        printf("Invalid choice! Press any key to continue...");
                        getch();
                    }
                }
                break;
            case 0:
                printf("\nExiting program... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Press any key to try again...");
                getch();
        }
    }

    return 0;
}
