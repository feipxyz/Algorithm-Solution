class MinStack {
public:
    MinStack() {
        // do intialization if necessary
    }

    /*
     * @param number: An integer
     * @return: nothing
     */
    void push(int number) {
        // write your code here
        m_stkSrc.push(number);
        int minnum = number;
        if (!m_stkOrder.empty() && m_stkOrder.top() < minnum)
        {
            minnum = m_stkOrder.top();
        }
        m_stkOrder.push(minnum);
    }

    /*
     * @return: An integer
     */
    int pop() {
        // write your code here
        int top = m_stkSrc.top();
        m_stkSrc.pop();
        m_stkOrder.pop();
        return top;
    }

    /*
     * @return: An integer
     */
    int min() {
        // write your code here
        return m_stkOrder.top();
    }

private:
    stack<int> m_stkSrc;
    stack<int> m_stkOrder;
};
