// A command is passed to higher level if lower level can't handle it.

class PurchaseRequest {
    let amount : Float
    let purpose : String

    init(amount: Float, purpose: String) {
        self.amount = amount
        self.purpose = purpose
    }
}

protocol PurchasePower {
    var successor : PurchasePower? {get set}
    func processRequest(amount: Int)
}


class ManagerPPower : PurchasePower {
    var successor : PurchasePower?

    init(successor: PurchasePower?) { self.successor = successor}

    func processRequest(amount: Int) {
        print("Manager processing the request \(amount)")
    }
}

class DirectorPPower : PurchasePower {
    var successor : PurchasePower?

    init(successor: PurchasePower?) {
        assert(successor != nil, "Set the manager")
        self.successor = successor
    }

    func processRequest(amount: Int) {
        if (amount < 10) {
            print("Director processing the request \(amount)")
        } else if (successor != nil){
            successor!.processRequest(amount)
        } else {
            print("Unable to handle this request")
        }
    }
}

class CheckAuthority {
    func main() {
        let pp : PurchasePower? = nil
        let mp = ManagerPPower(successor: pp)
        let dp = DirectorPPower(successor: mp)
        dp.processRequest(4)
    }
}

let ca = CheckAuthority()
ca.main()
