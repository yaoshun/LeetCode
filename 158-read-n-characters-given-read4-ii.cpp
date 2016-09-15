// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char staBuff[4];
    int staBuffSize=0;
    int offset=0;
    
public:
    int read(char *buf, int n) {
        int readSize = 0,r,ret=0;
        if (staBuffSize != 0){
            readSize = min(n, staBuffSize);
            memcpy(buf, staBuff + offset, readSize);
            offset += readSize;
            staBuffSize -= readSize;
            n -= readSize;
            if (staBuffSize > 0)
                return readSize;
        }
        offset = 0;
        //staBuffSize = 0;
        ret += readSize;
    
        while (n>0){    //有可能n<ret的
            r = read4(staBuff);
            
            readSize = min(r,n);
            memcpy(buf + ret, staBuff, readSize);
            ret += readSize;
            
            if(r<n){
                offset = 0;
                staBuffSize = 0;
                if(r<4)
                    return ret;
            }else{
                offset = n;
                staBuffSize = r - n;
            }
            
            n -= readSize;
        }
        return ret;                                 
    }
};
