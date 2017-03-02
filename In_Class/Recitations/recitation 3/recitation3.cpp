{\rtf1\ansi\ansicpg1252\cocoartf1343\cocoasubrtf160
{\fonttbl\f0\fnil\fcharset0 Consolas;}
{\colortbl;\red255\green255\blue255;\red0\green128\blue0;\red0\green0\blue255;\red163\green21\blue21;
\red43\green145\blue175;\red128\green128\blue128;\red111\green0\blue138;}
\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural

\f0\fs19 \cf0 \
\
\
\cf2 // A program that inserts and removes from linked lists\cf0 \
\cf2 // for practice in maintaining these lists.\cf0 \
\cf2 // A more complete program would worry more about\cf0 \
\cf2 // allocation and deallocation; this one simply maintains links.\cf0 \
\cf3 #include\cf0  \cf4 <iostream>\cf0 \
\cf3 using\cf0  \cf3 namespace\cf0  std;\
\
\cf3 #include\cf0  \cf4 "linked.h"\cf0 \
\
\cf3 int\cf0  main()\
\{\
	\cf5 SingleList\cf0  sing(2, 4);\
	\cf5 DoubleList\cf0  doub(2, 4);\
\
	cout << \cf4 "Single List:  insert 3, then 1, then 5"\cf0  << endl;\
	sing.print();\
	sing.insert(3);\
	sing.print();\
	sing.insert(1);\
	sing.print();\
	sing.insert(5);\
	sing.print();\
\
\cf2 //	return 0;				// temporary stopping point\cf0 \
\
	cout << \cf4 "Double List:  insert 3, then 1, then 5"\cf0  << endl;\
	doub.print();\
	doub.insert(3);\
	doub.print();\
	doub.insert(1);\
	doub.print();\
	doub.insert(5);\
	doub.print();\
\
	\cf2 //return 0;				// temporary stopping point\cf0 \
\
	cout << \cf4 "Double List:  remove 3, then 1, then 5"\cf0  << endl;\
	doub.remove(3);\
	doub.print();\
	doub.remove(1);\
	doub.print();\
	doub.remove(5);\
	doub.print();\
\
	\cf2 //return 0;				// temporary stopping point\cf0 \
\
	cout << \cf4 "Single List:  remove 3, then 1, then 5"\cf0  << endl;\
	sing.remove(3);\
	sing.print();\
	sing.remove(1);\
	sing.print();\
	sing.remove(5);\
	sing.print();\
\}\
\
\cf2 //  Creates a single linked list with two values\cf0 \
\cf2 //  Pre-condition:		value1 < value2\cf0 \
\cf5 SingleList\cf0 ::SingleList(\cf3 int\cf0  \cf6 value1\cf0 , \cf3 int\cf0  \cf6 value2\cf0 )\
\{\
	head = \cf3 new\cf0  \cf5 SingleNode\cf0 (\cf6 value1\cf0 );\
	tail = \cf3 new\cf0  \cf5 SingleNode\cf0 (\cf6 value2\cf0 );\
	head->next = tail;		\cf2 // head followed by tail\cf0 \
\}\
\
\cf2 //  prints the contents of a single-linked list\cf0 \
\cf3 void\cf0  \cf5 SingleList\cf0 ::print()\
\{\
	cout << \cf4 "Printing from "\cf0  << head->value << \cf4 " to "\cf0  << tail->value << \cf4 ": "\cf0 ;\
	\cf3 for\cf0  (\cf5 SingleNode\cf0  *node = head; node != \cf7 NULL\cf0 ; node = node->next)\
		cout << node->value << \cf4 " "\cf0 ;\
	cout << endl;\
\}\
\
\cf2 //  inserts a new element into a sorted single-linked list\cf0 \
\cf2 //  Pre-condition:	list is already sorted in increasing order\cf0 \
\cf3 void\cf0  \cf5 SingleList\cf0 ::insert(\cf3 int\cf0  \cf6 newValue\cf0 )\
\{\
	\cf5 SingleNode\cf0  *newNode = \cf3 new\cf0  \cf5 SingleNode\cf0 (\cf6 newValue\cf0 );\
	\cf5 SingleNode\cf0  *scan;\
\
	\cf3 if\cf0  (newNode->value < head->value)				\cf2 // condition needs a change\cf0 \
	\{\
		newNode->next = head;\
		head = newNode;\
\
\
	\}\
	\cf3 else\cf0 \
	\{\
		scan = head;\
		\cf3 while\cf0  (scan->next != \cf7 NULL\cf0  && scan->next->value < newNode->value)				\cf2 // condition needs a change\cf0 \
			scan = scan->next;\
		\cf3 if\cf0  (scan->next == \cf7 NULL\cf0 )\
		\{\
\
			tail = newNode;\
		\}\
\
		newNode->next = scan->next;		\cf2 // insert after scanned node\cf0 \
		scan->next = newNode;\
\
	\}\
\
\}\
\
\cf2 //  removes an element from a sorted single-linked list\cf0 \
\cf3 void\cf0  \cf5 SingleList\cf0 ::remove(\cf3 int\cf0  \cf6 value\cf0 )\
\{\
	\cf5 SingleNode\cf0  *removal;\
	\cf5 SingleNode\cf0  *scan;\
\
\
	scan = head;\
	\cf3 if\cf0  (scan->value == \cf6 value\cf0 )\
	\{\
		head = scan->next;\
\
	\}\
\
	\cf3 while\cf0  (scan->next != \cf7 NULL\cf0  && scan->next->value < \cf6 value\cf0 )\
		scan = scan->next;\
\
	\cf3 if\cf0  (scan->next != \cf7 NULL\cf0  && scan->next->value == \cf6 value\cf0 )\
	\{\
								removal = scan->next;\
\
		\cf3 if\cf0  (scan->next == tail)\
		\{\
\
				tail = scan;\
				scan->next = \cf7 NULL\cf0 ;\
		\}\
		\cf3 else\cf0 \{\
				scan->next = scan->next->next;\
\
		\}\
								\cf3 delete\cf0  removal;\
	\}\
\
\}\
	\
\
\
\cf2 //  Creates a double linked list with two values\cf0 \
\cf2 //  Pre-condition:		value1 < value2\cf0 \
\cf5 DoubleList\cf0 ::DoubleList(\cf3 int\cf0  \cf6 value1\cf0 , \cf3 int\cf0  \cf6 value2\cf0 )\
\{\
	head = \cf3 new\cf0  \cf5 DoubleNode\cf0 (\cf6 value1\cf0 );\
	tail = \cf3 new\cf0  \cf5 DoubleNode\cf0 (\cf6 value2\cf0 );\
	head->next = tail;		\cf2 // head followed by tail\cf0 \
	tail->prev = head;		\cf2 // tail preceded by head\cf0 \
\}\
\
\cf2 //  prints the contents of a double-linked list\cf0 \
\cf3 void\cf0  \cf5 DoubleList\cf0 ::print()\
\{\
	cout << \cf4 "Printing from "\cf0  << head->value << \cf4 " to "\cf0  << tail->value << \cf4 ": "\cf0 ;\
	\cf3 for\cf0  (\cf5 DoubleNode\cf0  *node = head; node != \cf7 NULL\cf0 ; node = node->next)\
		cout << node->value << \cf4 " "\cf0 ;\
	cout << endl;\
	cout << \cf4 "Reverse from "\cf0  << tail->value << \cf4 " to "\cf0  << head->value << \cf4 ": "\cf0 ;\
	\cf3 for\cf0  (\cf5 DoubleNode\cf0  *node = tail; node != \cf7 NULL\cf0 ; node = node->prev)\
		cout << node->value << \cf4 " "\cf0 ;\
	cout << endl;\
\}\
\
\cf2 //  inserts a new element into a sorted double-linked list\cf0 \
\cf2 //  Pre-condition:	list is already sorted in increasing order\cf0 \
\cf3 void\cf0  \cf5 DoubleList\cf0 ::insert(\cf3 int\cf0  \cf6 newValue\cf0 )\
\{\
	\cf5 DoubleNode\cf0  *newNode = \cf3 new\cf0  \cf5 DoubleNode\cf0 (\cf6 newValue\cf0 );\
	\cf5 DoubleNode\cf0  *scan;\
\
	\cf3 if\cf0  (newNode->value < head->value)				\cf2 // condition needs a change\cf0 \
	\{\
		newNode->next = head;\
		head->prev = newNode;\
		head = newNode;\
\
\
\
\
	\}\
	\cf3 else\cf0 \
	\{\
		scan = head;\
		\cf3 while\cf0  (scan->next != \cf7 NULL\cf0  && scan->next->value < newNode->value)				\cf2 // condition needs a change\cf0 \
			scan = scan->next;\
	\
		newNode->next = scan->next;	\
\
		\cf3 if\cf0  (scan->next == \cf7 NULL\cf0 )\
		\{\
\
			newNode->prev = tail;\
			tail = newNode;\
		\}\cf3 else\cf0 \
		scan->next->prev = newNode;\cf2 // insert after scanned node\cf0 \
		scan->next = newNode;\
		newNode->prev = scan;\
\
\
\
\
	\}\
\}\
\
\cf2 //  removes an element from a sorted double-linked list\cf0 \
\cf3 void\cf0  \cf5 DoubleList\cf0 ::remove(\cf3 int\cf0  \cf6 value\cf0 )\
\{\
	\cf5 DoubleNode\cf0  *removal;\
	\cf5 DoubleNode\cf0  *scan;\
\
	scan = head;\
	\cf3 while\cf0  (scan != \cf7 NULL\cf0  && scan->value < \cf6 value\cf0 )\
		scan = scan->next;\
	\cf3 if\cf0  (scan != \cf7 NULL\cf0  && scan->value == \cf6 value\cf0 )\
	\{\
		removal = scan;\
		\cf3 if\cf0  (scan == head)\
		\{	head = scan->next;\
		head->prev = \cf7 NULL\cf0 ;\
	\}\
		\cf3 else\cf0  \cf3 if\cf0  (scan == tail)\
		\{\
			tail = scan->prev;\
			tail->next = \cf7 NULL\cf0 ;\
		\}\
		\cf3 else\cf0 \{\
			scan->next->prev = scan->prev;\
			scan->prev->next = scan->next;\
		\}\
		\cf3 delete\cf0  removal;\
	\}\
\}}