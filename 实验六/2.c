#include "struct.h"

int main()
{
    LinkList *L = (LinkList *)malloc(sizeof(LinkList));
    CreateLinkList(L);
    ShowLinkList(L);
    ShowNodeAverage(L);
    return 0;
}