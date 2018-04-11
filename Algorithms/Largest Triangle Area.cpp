class Solution {
public:
    double getDistance(vector<int> pt1, vector<int> pt2){
        return sqrt(pow((pt1[0] - pt2[0]), 2) + pow((pt1[1] - pt2[1]), 2));
    }
    
    double getAreaOfTriangle(double& a, double& b, double& c){
        double s = (a + b + c)/2;
        
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }
    
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        
        double ans = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(int k = j + 1; k < n; k++){
                    double a = getDistance(points[i], points[j]);
                    double b = getDistance(points[j], points[k]);
                    double c = getDistance(points[i], points[k]);
                    ans = max(ans, getAreaOfTriangle(a, b, c));         
                }
            }
        }
        
        return ans;
    }
};
