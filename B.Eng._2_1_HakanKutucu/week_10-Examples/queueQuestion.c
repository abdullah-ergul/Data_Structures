/*
    You are given a queue q1. Write a program that adds the values of q1 into a new queue q2 if the value is even, or new queue q3 otherwise.
    You can use queue methods (enqueue, dequeue etc.)
*/

void queueQuestion (queue *q1) {
    queue q2, q3;
    initialize(&q2);
    initialize(&q3);

    while (!isEmpty(q1)) {
        int x= dequeue(q1);

        if(x % 2 == 0)
            enqueue(&q2, x);
        else
            enqueue(&q3, x);
    }
}