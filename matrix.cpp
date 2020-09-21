const int mod = 1e9 + 7;

template <typename T>
class Matrix {
 public:
    
    vector < vector <T> > A;
    int r, c;
    Matrix(int r, int c){                                 
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c));
    }

    Matrix(int r, int c, T val){                           
        this->r = r;
        this->c = c;
        A.assign(r , vector <T> (c , val));
    }

    Matrix(int n){                                        
        this->r = this->c = n;
        A.assign(n , vector <T> (n));
        for(int i=0;i<n;i++)
            A[i][i] = (T)1;
    }
    Matrix operator * (Matrix &B){                      
        assert(c == B.r);
        int i, j, k, x = r, y = c, z = B.c;

        Matrix <T> C(x,z,0);
        
        for(i=0 ; i<x ; i++)
            for(j=0 ; j<z ; j++)
                for(k=0 ; k<y ; k++)
                    C[i][j] = (C[i][j] + ( (int)A[i][k] * (int)B[k][j] ) )%mod;

        return C;
    }

    Matrix operator ^ (int n){                          
        assert(r == c);

        int i, j;
        Matrix C(r);

        Matrix X(r,c,0);
        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                X[i][j] = A[i][j];

        while(n){
            if(n&1)
                C = C * X;

            X = X * X;
            n /= 2;
        }
        return C;
    }

};
