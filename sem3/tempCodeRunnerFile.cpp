while (i < nl && j < nr)
            {
                if (larr[i] <= rarr[j])
                {
                    arr[k] = larr[i];
                    i++;
                }
                else
                {
                    arr[k] = rarr[j];
                    j++;
                }
                k++;
            }
            while (i < nl)
            { 
                arr[k] = larr[i];
                i++;
                k++;
            }
            while (j < nr)
            { 
                arr[k] = rarr[j];
                j++;
                k++;
            }
        }