/*
 *
 * Name:	�����ͨ��������linux�ں˷�װ����C��
 * Auther:	chishaxie
 * Date:	2012.7.29
 *
 * Description:	log(n)�Ĳ��롢ɾ������ѯ��������������
 *
 */
#ifndef _RBTREE_CONTAINER_H_
#define _RBTREE_CONTAINER_H_

#include "rbtree.h"

typedef struct
{
	struct rb_node rb_node; //rbtree�ں˽ṹ������Ϊ�׸��ֶΣ�
	size_t dlen; //data�ĳ���
	void *key; //ָ�������������
	unsigned char *data; //ָ��ֵ
} rbtree_container_node; //�ڵ�

typedef int (*key_compare)(void *key1, void *key2);

typedef struct
{
	struct rb_root root; //rbtree�ں˽ṹ
	size_t klen; //key�ĳ��ȣ�����key��
	key_compare compare; //key�ıȽϺ���
} rbtree_container; //����

#define rbtree_container_node_set_key(pnode,type,value) (*((type*)((pnode)->key)) = (value))

void rbtree_container_init(rbtree_container *tree, size_t key_length, key_compare key_compare_function);

rbtree_container_node* rbtree_container_search(rbtree_container *tree, void *key);
rbtree_container_node* rbtree_container_abslowest(rbtree_container *tree, void *key);
rbtree_container_node* rbtree_container_sub(rbtree_container *tree, void *key);

int rbtree_container_insert(rbtree_container *tree, rbtree_container_node *cont);

rbtree_container_node *rbtree_container_delete(rbtree_container *tree, void *key);

rbtree_container_node *rbtree_container_replace(rbtree_container *tree, rbtree_container_node *cont);

rbtree_container_node *rbtree_container_first(rbtree_container *tree);

rbtree_container_node *rbtree_container_last(rbtree_container *tree);

rbtree_container_node *rbtree_container_next(rbtree_container_node *cont);

rbtree_container_node *rbtree_container_prev(rbtree_container_node *cont);

void rbtree_container_erase(rbtree_container *tree, rbtree_container_node *cont);

rbtree_container_node *rbtree_container_node_malloc(rbtree_container *tree, size_t data_length);

rbtree_container_node *rbtree_container_node_array_malloc(rbtree_container *tree,
	size_t data_length, size_t array_length);

void rbtree_container_node_free(rbtree_container_node *tree_node);

#endif
