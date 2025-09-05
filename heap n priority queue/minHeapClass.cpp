class heap{
    int * arr;
    int size = 100000;
    int last = -1;
    public:

        void initialize(){
          arr = new int[size];
        }

        void insert(int key){
            last++;
            int i = last;
            while(i>0 && key<arr[(i-1)/2]){
                arr[i] = arr[(i-1)/2];
                i = (i-1)/2;
            }
            arr[i] = key;
        }

        void changeKey(int index, int new_val){
            if (arr[index] == new_val) return;
            int j = index;
            arr[j] = new_val;
            int i = (j-1)/2;
            // if(i<0)return;
            if(i>=0 && arr[j]<arr[i]){
                //heapify up
                while(j>0 && arr[j]<arr[i]){
                      int temp = arr[i];
                      arr[i] = arr[j];
                      arr[j] = temp;
                      j = i;
                      i = (j-1)/2;
                }
            }else{
                //heapify down
                i = j; j = i*2+1;
                while(j<=last){
                    if(j+1<=last && arr[j+1]<arr[j])j++;
                    if(arr[j]<arr[i]){
                      int temp = arr[i];
                      arr[i] = arr[j];
                      arr[j] = temp;
                     i = j; j = i*2+1;
                    }else break;
                }
            }
        }

        void extractMin(){
            arr[0] = arr[last];
            last--;
            int i = 0 , j = i*2+1;
            while(j<=last){
                if(arr[j+1]<arr[j])j++;
                if(arr[j]<arr[i]){
                    int temp = arr[j];
                    arr[j] = arr[i];
                    arr[i] = temp;
                    i = j;
                    j = i*2+1;
                }else break;
            }
        }

        bool isEmpty(){
            return (last<0);
        }

        int getMin(){
            return arr[0];
        }

        int Size(){
            return last+1;
        }
};