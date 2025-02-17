import java.util.*;
import java.io.*;

public class Main {
    private static int N;
    private static int[][] costs;
    private static int[][] visited;
    private static int minCost = Integer.MAX_VALUE;
    private static int[] di = {0, 1, 0, -1};
    private static int[] dj = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        visited = new int[N][N];
        costs = new int[N][N];
        
        for(int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j = 0; j < N; j++) {
                costs[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        dfs(0, 0);

        System.out.println(minCost);

    }
    private static void dfs(int numOfSeed, int accCost) {
        if(accCost > minCost) {return;}
        if(numOfSeed == 3) {
            if(minCost > accCost) {
                minCost = accCost;
            }
            return;
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                int[] seed = {i,j};
                if(isInAndCanFlower(seed)){
                    int cost = visitedCheckAndgetCost(seed);
                    dfs(numOfSeed + 1, accCost + cost);
                    undoVisited(seed);
                }
                
            }
        }
    }

    private static int visitedCheckAndgetCost(int[] seed) {
        int i = seed[0];
        int j = seed[1];
        int cost = costs[i][j];

        visited[i][j] = 1;

        for(int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            visited[ni][nj] = 1;
            cost += costs[ni][nj];
        }
        return cost;
    }

    private static void undoVisited(int[] seed) {
        int i = seed[0];
        int j = seed[1];

        visited[i][j] = 0;

        for(int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            visited[ni][nj] = 0;
        }
    }

    private static boolean isInAndCanFlower(int[] seed) {
        int i = seed[0];
        int j = seed[1];
        if(visited[i][j] != 0) {return false;}

        for(int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(0 > ni || ni >= N || 0 > nj || nj >= N || visited[ni][nj] != 0) {return false;}
        }

        return true;
    }
    
}
