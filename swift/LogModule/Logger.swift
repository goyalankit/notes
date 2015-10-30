class Logger
{
    var prefix: String

    init(_ prefix: String)
    {
        self.prefix = prefix
    }

    func log<T>(object: T)
    {
        print(prefix)
        print(object)
    }
}
