/*
 *	Based on a video from mCodeing YT chanel
 *	https://youtu.be/AmjoK55h68Y
 *	explaining machanics of unique_ptr
 * 
 */

#include <utility>


template <class T>
class custom_unique_pte
{
public:
	explicit custom_unique_pte(T* ptr_) noexcept : m_ptr{ ptr_ }
	{}
	custom_unique_pte() noexcept : custom_unique_pte(nullptr)
	{}

	custom_unique_pte(const custom_unique_pte&) = delete;
	custom_unique_pte& operator=(const custom_unique_pte&) = delete;

	custom_unique_pte(custom_unique_pte&& other) noexcept : m_ptr{ other.release() } {}
	custom_unique_pte& operator=(custom_unique_pte&& other) noexcept 
	{
		if (this != &other) 
		{
			reset(other.release());
		}
		return *this;
	}


	~custom_unique_pte()
	{
		if (m_ptr != nullptr) // if (ptr)
		{
			delete m_ptr;
		}
	}

	T* release() noexcept {
		// T* old = m_ptr;
		// m_ptr = nullptr;
		// return old;
		return std::exchange(m_ptr, nullptr);
	}

	void reset(T* ptr_ = nullptr) noexcept {
		// T* old = m_ptr;
		// m_ptr = ptr_;
		T* old = std::exchange(m_ptr, ptr_);

		if (old) // if (old != nullptr)
			delete old;
	}

private:
	T * m_ptr;


public:
	// operations
	explicit operato bool() const noexcept 
	{ 
		return static_cast<bool>(m_ptr); 
	}

	T * get() const noexcept { return m_ptr; }
	
	T* ooperator->() const noexcept { return m_ptr; }

	T& operator*() const noexcept { return *m_ptr; }


};

int main(void)
{
	return 0;
}