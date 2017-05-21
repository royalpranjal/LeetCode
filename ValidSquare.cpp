class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        float s1, s2, s3, s4;
        
        s1 = sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
        s2 = sqrt(pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2));
        s3 = sqrt(pow(p3[0] - p4[0], 2) + pow(p3[1] - p4[1], 2));
        s4 = sqrt(pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2));
        
        if(s1 == s2 && s2 == s3 && s3 == s4 && s4 == s1){
            double m1, m2, m3, m4;
            
            if(p1[0] - p2[0] != 0){
                m1 = (p1[1]-p2[1]);
                m1 = m1/(p1[0]-p2[0]);
            }
            else{
                m1 = INT_MAX;
            }
            
            if(p2[0] - p3[0] != 0){
                m2 = (p2[1]-p3[1]);
                m2 = m2/(p2[0]-p3[0]);
            }
            else{
                m2 = INT_MAX;
            }
            
            if(p3[0] - p4[0] != 0){
                m3 = (p3[1]-p4[1]);
                m3 = m3/(p3[0]-p4[0]);
            }
            else{
                m3 = INT_MAX;
            }
            
            if(p4[0] - p1[0] != 0){
                m4 = (p4[1]-p1[1]);
                m4 = m4/(p4[0]-p1[0]);
            }
            else{
                m4 = INT_MAX;
            }
            
            cout << "Case 1" << endl;
            cout << "s1 : " << s1 << ", s2 : " << s2 << ", s3 : " << s3 << ", s4 : " << s4 << endl;
            cout << "m1 : " << m1 << ", m2 : " << m2 << ", m3 : " << m3 << ", m4 : " << m4 << endl;
            
            if(m1 == INT_MAX || m2 == INT_MAX || m3 == INT_MAX || m4 == INT_MAX){
                if(m1 == INT_MAX && m3 == INT_MAX && m2 == 0 && m4 == 0){
                    return true;
                }
                if(m2 == INT_MAX && m4 == INT_MAX && m1 == 0 && m3 == 0){
                    return true;
                }
            }
            // else if(m1*m2 == -1 && m2*m3 == -1 && m3*m4 == -1 && m4*m1 == -1){
            //     return true;
            // }
            else{ 
            // if(m1*m2 == m2*m3 && m2*m3 == m3*m4 && m3*m4 == m4*m1){
            //     return true;
            // }
                float f12 = (p1[1]-p2[1])*(p2[1]-p3[1]);
                f12 = f12/(p1[0]-p2[0]);
                f12 = f12/(p2[0]-p3[0]);
                
                float f23 = (p2[1]-p3[1])*(p3[1]-p4[1]);
                f23 = f23/(p2[0]-p3[0]);
                f23 = f23/(p3[0]-p4[0]);
                
                
                if(f12 == -1 && f23 == -1){
                  return true; 
                }
            }
        }
        
        s1 = sqrt(pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2));
        s2 = sqrt(pow(p2[0] - p4[0], 2) + pow(p2[1] - p4[1], 2));
        s3 = sqrt(pow(p3[0] - p2[0], 2) + pow(p3[1] - p2[1], 2));
        s4 = sqrt(pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2));
        
        if(s1 == s2 && s2 == s3 && s3 == s4 && s4 == s1){
            double m1, m2, m3, m4;
            
            if(p1[0] - p4[0] != 0){
                m1 = (p1[1]-p4[1]);
                m1 = m1/(p1[0]-p4[0]);
            }
            else{
                m1 = INT_MAX;
            }
            
            if(p2[0] - p4[0] != 0){
                m2 = (p2[1]-p4[1]);
                m2 = m2/(p2[0]-p4[0]);
            }
            else{
                m2 = INT_MAX;
            }
            
            if(p3[0] - p2[0] != 0){
                m3 = (p3[1]-p2[1]);
                m3 = m3/(p3[0]-p2[0]);
            }
            else{
                m3 = INT_MAX;
            }
            
            if(p3[0] - p1[0] != 0){
                m4 = (p3[1]-p1[1]);
                m4 = m4/(p3[0]-p1[0]);
            }
            else{
                m4 = INT_MAX;
            }
            
            cout << "Case 2" << endl;
            cout << "s1 : " << s1 << ", s2 : " << s2 << ", s3 : " << s3 << ", s4 : " << s4 << endl;
            cout << "m1 : " << m1 << ", m2 : " << m2 << ", m3 : " << m3 << ", m4 : " << m4 << endl;
            
            if(m1 == INT_MAX || m2 == INT_MAX || m3 == INT_MAX || m4 == INT_MAX){
                if(m1 == INT_MAX && m3 == INT_MAX && m2 == 0 && m4 == 0){
                    return true;
                }
                if(m2 == INT_MAX && m4 == INT_MAX && m1 == 0 && m3 == 0){
                    return true;
                }
            }
            else{ 
                // if(m1*m2 == m2*m3 && m2*m3 == m3*m4 && m3*m4 == m4*m1){
                //     return true;
                float f12 = (p1[1]-p4[1])*(p2[1]-p4[1]);
                f12 = f12/(p1[0]-p4[0]);
                f12 = f12/(p2[0]-p4[0]);
                
                float f23 = (p2[1]-p4[1])*(p3[1]-p2[1]);
                f23 = f23/(p2[0]-p4[0]);
                f23 = f23/(p3[0]-p2[0]);
                
                
                if(f12 == -1 && f23 == -1){
                  return true; 
                }
            }
        }
        
        s1 = sqrt(pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2));
        s2 = sqrt(pow(p4[0] - p3[0], 2) + pow(p4[1] - p3[1], 2));
        s3 = sqrt(pow(p2[0] - p4[0], 2) + pow(p2[1] - p4[1], 2));
        s4 = sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2));
        
        if(s1 == s2 && s2 == s3 && s3 == s4 && s4 == s1){
            double m1, m2, m3, m4;
            
            if(p1[0] - p3[0] != 0){
                m1 = (p1[1]-p3[1]);
                m1 = m1/(p1[0]-p3[0]);
            }
            else{
                m1 = INT_MAX;
            }
            
            if(p4[0] - p3[0] != 0){
                m2 = (p4[1]-p3[1]);
                m2 = m2/(p4[0]-p3[0]);
            }
            else{
                m2 = INT_MAX;
            }
            
            if(p2[0] - p4[0] != 0){
                m3 = (p2[1]-p4[1]);
                m3 = m3/(p2[0]-p4[0]);
            }
            else{
                m3 = INT_MAX;
            }
            
            if(p2[0] - p1[0] != 0){
                m4 = (p2[1]-p1[1]);
                m4 = m4/(p2[0]-p1[0]);
            }
            else{
                m4 = INT_MAX;
            }
            
            cout << "Case 3" << endl;
            cout << "s1 : " << s1 << ", s2 : " << s2 << ", s3 : " << s3 << ", s4 : " << s4 << endl;
            cout << "m1 : " << m1 << ", m2 : " << m2 << ", m3 : " << m3 << ", m4 : " << m4 << endl;
            
            if(m1 == INT_MAX || m2 == INT_MAX || m3 == INT_MAX || m4 == INT_MAX){
                if(m1 == INT_MAX && m3 == INT_MAX && m2 == 0 && m4 == 0){
                    return true;
                }
                if(m2 == INT_MAX && m4 == INT_MAX && m1 == 0 && m3 == 0){
                    return true;
                }
            }
            else{
                // if(m1*m2 == m2*m3 && m2*m3 == m3*m4 && m3*m4 == m4*m1){
                // return true;
                float f12 = (p1[1]-p3[1])* (p4[1]-p3[1]);
                f12 = f12/(p1[0]-p3[0]);
                f12 = f12/(p4[0]-p3[0]);
                
                float f23 = (p4[1]-p3[1])*(p2[1]-p4[1]);
                f23 = f23/(p4[0]-p3[0]);
                f23 = f23/(p2[0]-p4[0]);
                
                
                if(f12 == -1 && f23 == -1){
                  return true; 
                }
            }
        }
        
        return false;
    }
};
