#include<stdio.h>
#include<stdlib.h>

/*Problem:

You are given Q queries. Each query has three integers: X[k], Y[k], and N[k].

For each query k, compute the result of the query as:

    Result[k] = ((X[k] + 0) * Y[k]) ^ ((X[k] + 1) * Y[k]) ^ ... ^ ((X[k] + N[k]) * Y[k])

Where ^ denotes the bitwise XOR operation, and you perform this operation for all i from 0 to N[k].

Finally, compute the sum of results for all Q queries:
    Final Result = (sum(Result[k] for k = 0 to Q-1)) % (10^9 + 7)

*/

int main(){

    int q;
    scanf("%d",&q);

    int x[q],y[q],n[q],arr[q];
    for(int i=0;i<q;i++)
        scanf("%d",&x[i]);

    for(int i=0;i<q;i++)
        scanf("%d",&y[i]);

    for(int i=0;i<q;i++)
        scanf("%d",&n[i]);

    for(int i=0;i<q;i++){
        arr[i]=0;
        for(int j=0;j<=n[i];j++){
            arr[i]=arr[i]^((x[i]+j)*y[i]);
        }
    }

    int sum=0;
    for(int i=0;i<q;i++){
        sum+=arr[i];
    }

    printf("%d",sum%1000000007);
    return 0;
}