原子变量
	mydev_st
		---->count++
自旋锁
	spinlock_t
	1.如果单核cpu，内核不支持抢占，自旋锁无效
	2.单核cpu，内核支持抢占，加锁==禁止抢占 解锁==使能抢占
	3.多核cpu
	在等锁时会占着一个CPU不放，不会睡眠，可以在中断上下文使用
	注意：1.自死锁 2.ABBA死锁 3.带着锁不能睡眠 4.在函数返回之前要解锁
	读写锁（自旋锁）	
	include/linux/rwlock.h
信号量
	include/linux/semaphore.h
	加锁不成功的化会睡眠等待
互斥量
	include/linux/mutex.h
读写锁
	读写自旋锁
	读写信号量
	优先读者，读锁可以重复加。可以有多个读者存在，只能有一个写着存在。问题：饿死写着
seq锁
	可以有多个读者存在，只能有一个写着存在。
	写者来过，后续读者就不能再读。
	基于自旋锁
	写者优先
	include/linux/seqlock.h



