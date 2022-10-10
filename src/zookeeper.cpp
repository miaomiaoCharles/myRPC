#include "zookeeper.hpp"
#include "rpcApplication.hpp"
void global_watcher(zhandle_t *zh, int type, int state, const char *path, void *watcherCtx)
{
    if (type == ZOO_SESSION_EVENT)
    {
        if (state == ZOO_CONNECTED_STATE) // zkclient和zkserver连接成功
        {
            sem_t *sem = (sem_t *)zoo_get_context(zh);
            sem_post(sem);
        }
    }
}

ZKClient::ZKClient() : _zhandle(nullptr) {}

ZKClient::~ZKClient()
{
    if (_zhandle != nullptr)
    {
        zookeeper_close(_zhandle);
    }
}

void ZKClient::start()
{
    string host = RpcApplication::getRpcApplication().GetConfig().load("zookeeperip");
    string port = RpcApplication::getRpcApplication().GetConfig().load("zookeeperport");
    string connStr = host + ":" + port;
    _zhandle = zookeeper_init(connStr.c_str(), global_watcher, 30000, nullptr, nullptr, 0);
    if (nullptr == _zhandle) 
    {
        std::cout << "zookeeper_init error!" << std::endl;
        exit(EXIT_FAILURE);
    }

    sem_t sem;
    sem_init(&sem,0,0);
    zoo_set_context(_zhandle, &sem);

    sem_wait(&sem);
    cout << "与zookeeper连接成功啦" << endl;

}

void ZKClient::create(const char *path, const char *data, int datalen, int state)
{
    char path_buffer[128];
    int bufferlen = sizeof(path_buffer);
    int flag;
	// 先判断path表示的znode节点是否存在，如果存在，就不再重复创建了
	flag = zoo_exists(_zhandle, path, 0, nullptr);
	if (ZNONODE == flag) // 表示path的znode节点不存在
	{
		// 创建指定path的znode节点了
		flag = zoo_create(_zhandle, path, data, datalen,
			&ZOO_OPEN_ACL_UNSAFE, state, path_buffer, bufferlen);
		if (flag == ZOK)
		{
			std::cout << "znode create success... path:" << path << std::endl;
		}
		else
		{
			std::cout << "flag:" << flag << std::endl;
			std::cout << "znode create error... path:" << path << std::endl;
			exit(EXIT_FAILURE);
		}
	}
}

string ZKClient::getData(const char *path)
{
    char buffer[64];
	int bufferlen = sizeof(buffer);
	int flag = zoo_get(_zhandle, path, 0, buffer, &bufferlen, nullptr);
	if (flag != ZOK)
	{
		std::cout << "get znode error... path:" << path << std::endl;
		return "";
	}
	else
	{
		return buffer;
	}
}