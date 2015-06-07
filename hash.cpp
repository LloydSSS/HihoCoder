/*
//hashmap
struct hashnode {
    char str[L];
    int key;
    struct hashnode *next;
} nodes[N << 1], *hashtable[N];

int hashid = 0;
int hashfind(int hashkey, char *s)
{
    struct hashnode *node;
    for (node = hashtable[hashkey]; node && strcmp(node->str, s); node = node->next)
        ;
    return node == NULL ? -1 : (node - nodes);
}

int hashinsert(int hashkey, char *s, int key)
{
    strcpy(nodes[hashid].str, s);
    nodes[hashid].key = key;
    nodes[hashid].next = hashtable[hashkey];
    hashtable[hashkey] = &nodes[hashid];
    return hashid++;
}

int hashcode(char *str)
{
    unsigned int seed = 13131; // 31 131 1313 13131 131313 ..
    unsigned int hash = 0;
    while (*str)
        hash = hash * seed + (*str++);
    return (hash & 0x7FFFFFFF);
}
*/
