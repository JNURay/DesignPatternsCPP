# Singleton (单例)

## Description (介绍)

Ensure a class only has one instance, and provide a global point of access to it.   
保证一个类仅有一个实例，并提供一个访问它的全局访问点。

### When to Use (适用性)

- there must be exactly one instance of a class, and it must be accessible to clients from a well-known access point.  
当类只能有一个实例而且客户可以从一个众所周知的访问点访问它时。
- when the sole instance should be extensible by subclassing, and clients should be able to use an extended instance without modifying their code  
当这个唯一实例应该是通过子类化可扩展的，并且客户应该无须更改代码就能使用一个扩展的实例时。

## Structure (结构)
![Singleton Structure](structure.png)
