class Solution
{
public:
    struct node
    {
        char str;
        node *next;
    };
    node *temp = NULL;

    void push(char a)
    {
        if (temp == NULL)
        {
            temp = new node();
            temp->str = a;
            temp->next = NULL;
        }
        else
        {
            node *temp1 = new node();
            temp1->str = a;
            temp1->next = temp;
            temp = temp1;
        }
    }
    void pop()
    {
        if (temp != NULL)
        {
            node *temp2 = temp;
            temp = temp->next;
            delete temp2;
        }
    }

    bool isValid(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            //cout<<str<<'\n';
            if (i == 0)
            {
                if (s[i] == ')')
                    return false;
                else if (s[i] == '}')
                    return false;
                else if (s[i] == ']')
                    return false;
                else
                    push(s[i]);
            }
            else
            {
                if (s[i] == ')')
                {
                    if (temp != NULL)
                    {
                        if (temp->str == '(')
                            pop();
                        else
                            return false;
                    }
                    else
                        return false;
                }
                else if (s[i] == '}')
                {
                    if (temp != NULL)
                    {
                        if (temp->str == '{')
                            pop();
                        else
                            return false;
                    }
                    else
                        return false;
                }
                else if (s[i] == ']')
                {
                    if (temp != NULL)
                    {
                        if (temp->str == '[')
                            pop();
                        else
                            return false;
                    }
                    else
                        return false;
                }
                else
                    push(s[i]);
            }
        }
        if (temp == NULL)
            return true;
        return false;
    }
};