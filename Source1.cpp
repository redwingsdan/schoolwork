#include <cstudio>
#include <cstring>
#include <vector>
using namespace std;

const int N = 105, L = 50;
bool tag[N];
vector<int> adj_list[N];
vector<int> component[N];

void init(int node_count);
void dfs(int u);
void print_ans();

int main()
{
char fname[L];
int node_count, edge_count, u, v;
printf("Enter the name of the file: ");
scanf("%s", fname);
freopen(fname, "r", stdin);
scanf("%d%d", &edge_count, &node_count);
init(node_count);
for(int i = 0; i < edge_count; i++)
{
scanf("%d%d", &u, &v);
adj_list[u].push_back(v);
adj_list[v].push_back(u);
}

for(int i = 1; i <= node_count; i++){
if(!tag[i]){
++component_count;
tag[i] = true;
dfs(i);
}
}
print_ans();
}

void init(int node_count){
for(int i = 1; i <= node_count; ++i){
adj_list[i].clear();
component[i].clear();
}
memset(tag, 0, sizeof(tag));
component_count = 0;
}

void dfs(int u){
component[component_count - 1].push_back(u);
int adj_count = adj_list[u].size();

for(int i = 0; i < adj_count; i++)
{
int v = adj_list[u][i];
if(!tag){
tag[v] = true;
dfs(v);
}
}
}

void print_ans()
{
for(int i = 0; i < component_count; ++i){
int component_size = component[i].size();
printf("Connected Component #%d:\n", i + 1);
for(int j = 0; j <component_size; ++j){
if(j){
printf(" ");
}
printf("%d", component[i][j]);
}
printf("\n");
}
}