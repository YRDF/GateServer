        C++编程的一个http邮箱注册服务器
        Server启动后监听连接
        当对方有连接之后交给HttpConnection进行管理
        HttpConnection::Start()监听读事件，用HandleReq()处理读请求，CheckDeadline()检测是否超时
        HandleReq()处理读请求调用底层LogicSystem()逻辑层处理，传入请求的url和智能指针
        LogicSystem()::LogicSystem()可以对url进行注册
        在HandleGet()中，查找url是否在map中注册，如果没有在map中注册就返回false。
        注册过就用_get_handlers[path](con);进行回调，参数con。
        在HandleReq()中调用LogicSystem()中的HandleGet()，如果成功就WriteResponse()进行写操作
        如果在规定时间写完就取消定时器，超时就关闭socket。
        收到客户端请求后，在LogicSystem()::LogicSystem()中的RegPost中进行注册
        RegPost中调用VarifyGrpcClient::GetInstance()->GetVarifyCode请求验证码
        VarifyServer服务器发送验证码并通知本服务器，LogicSystem::LogicSystem的RegGet中获取验证码
        通过ConfigMgr来对comfig.ini中固定的内容进行管理。
        用线程池让gateserver并发
        搭建redis服务器
        自己搞了一天，也没搞好ubuntu&docker&mysql&navicat的连通，老是报错。需要重新研究。
        发现是因为本地连接本地虚拟机mysql的原因。暂时使用本地的ip，mysql。
        使用Mysql Connector C++ 这个库来访问mysql。
        封装mysql连接池，封装DAO操作层。
        使用navicat创建数据库zzz1，zzz1三剑客添加user表和user_id表，新建存储过程。
        建立一个数据库管理者MysqlDao类用来实现服务层，对接逻辑层的调用，更改逻辑层RegPost代码，查找数据库。