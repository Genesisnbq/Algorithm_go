//
// Created by Genes on 2020/10/29.
//
// X��������
// ����

#include<cstdio>

typedef long long ll;

const int N = (1 << 20) + 10;

int primes[N];// ������
int min_p[N]; //����С������
int cnt;
bool st[N]; // ��ʾ��ӦԪ���Ƿ�ɸ��

// ����ɸ��(ŷ��ɸ��)
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            min_p[i] = i;
            primes[++cnt] = i;
        }
        for (int j = 1; primes[j] * i <= n; j++) {
            int t = primes[j] * i;
            st[t] = true; //��Ǻ���
            min_p[t] = primes[j];
            if (i % primes[j] == 0) {
                //���i��ǰ��ĳ�������ı���ʱ, ˵��i�Ժ����ĳ��������������С����ɸȥ
                //ͬ��, ֮���ɸ��Ҳ��û�б�Ҫ��, ��������ʱ��, �Ϳ�������ѭ����
                break;
            }
        }
    }
}
int sum[N]; //��¼ÿ�������ӳ��ֵĴ���

int main() {
    get_primes(N);
    int x;
    while (~scanf("%d", &x)) {
        //tol���ڼ�¼��󳤶�,k��ʾ��i�������ӵ��±�, ��0��ʼ
        int k = 0, tol = 0;

        // ���δ������������, �����Ӧ�����ӳ��ֵĴ���
        while (x > 1) {
            int p = min_p[x]; // ͨ��while, ����ȡ����С������
            sum[k] = 0;

            //����ǰ������, ������ֵĴ���
            while (x % p == 0) {
                sum[k]++;
                tol++;
                x /= p;
            }
            k++; // ׼��������һ��������
            /*
             ��:
                x=12 --> 3*2^2
                p = 2
                sum[1]=1
                x=6

                sum[1]=2
                x=3
                ****************
                p=3
                sum[2]=1
                x=1 --> ����
             */
        }

        //�����������ӳ����ܴ�����ȫ����
        ll res = 1;
        for (int i = 2; i <= tol; i++) {
            res *= i; // tol!
        }
        //ȥ�������������ظ����ֵĴ���
        for (int i = 0; i < k; i++) {
            for (int j = 1; j <= sum[i]; j++) {
                res /= j;
            }
        }
        printf("%d %lld\n", tol, res); //�������еĳ���, �Լ�������󳤶ȵ����еĸ���
    }
    return 0;
}