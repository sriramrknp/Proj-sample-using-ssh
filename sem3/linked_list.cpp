class node
{
public:
    int accounNum;
    double accountBlc;
    node *next;
};

node *headSA = NULL;
node *headCA = NULL;
node *nodeSA = new node();
node *nodeCA = new node();

if (headSA == NULL)
{
    cout << "accnum in list: " << endl;
    nodeSA->accounNum = accnum;
    nodeSA->accountBlc = accblc_sa;
    nodeSA->next = NULL;
}
else
{
    node *ptrSA = new node();
    ptrSA->accounNum = accnum;
    ptrSA->accountBlc = accblc_sa;
    ptrSA->next = NULL;
    nodeSA->next = ptrSA;
    nodeSA = ptrSA;
}

if (headSA == NULL)
{
    headSA = nodeSA;
}
