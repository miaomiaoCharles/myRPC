# myRPC
这是一个基于protobuf的RPC网络通信框架，可以实现函数的远程调用功能，并且使用了自己写的网络库框架，使其能够接受高并发的远程函数调用。其中数据的序列化及其反序列化由protobuf实现，使用zookeeper作为服务器中间件。数据的发送及其回调由我写的另一个网络库框架实现：https://github.com/miaomiaoCharles/NetLibrary

**项目动机：**

想比起集群与单体的服务器，分布式的服务器有以下优点：

1. 如果仅仅修改一小部分代码，仅仅需要部署该部分代码的服务器重新编译并重启服务即可，其他服务器不需要改动。而集群服务器架构需要所有服务器重新编译代码与部署。
2. 实际上，代码各个部分对硬件的需求是不一样的，有的对I/O速度需求高，有的对CPU要求高。分布式可以根据硬件条件将不同的代码部署在不同的服务器上，这是集群做不到的。

综上所述， 在实际应用中，分布式是很常见的服务器管理模式。因此就**需要一种通信框架来让服务器之间相互调用函数，从而实现服务器之间的通信，进而形成分布式架构**。

**使用说明**：

在工作目录下，输入命令行：.

```bash
sudo ./autobuild.sh
```

之后会自动执行脚本，完成编译，并生成框架的静态库。

使用可以参考example中的使用用例，编译后会生成调用方的客户端和提供方的客户端。（这里的调用方指的是远程想使用函数的服务器，但是该函数并不在本地实现，需要发送函数名与参数给别的服务器调用，之后别的服务器返回函数调用结果。而提供方指的是提供该函数的服务器，即函数的实现代码在该服务器上存储）。

首先RPC框架前，需要在/bin目录的配置文件里填写配置信息，填写RPC节点的ip与port，以及zookeeper的ip与port。之后启动提供方客户端，输入以下指令：

```bash
./provider -i testConfig.conf
```

其中的[testConfig.conf](https://github.com/miaomiaoCharles/-muduo-protobuf-rpc-/blob/main/bin/testConfig.conf)是配置文件名字。启动后，提供方将进入监听状态，当有函数调用请求时，将执行本地函数并返回结果。
