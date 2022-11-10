void printAll(queue *q){
    int i= q->front;
    while(i != q->rare){
        printf("%d\n",q->data[i]);
        i++;
        if(i == QUEUE_SIZE)
            i= 0;
    }
    printf("Done!");
}
