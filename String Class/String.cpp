#include <ostream>
#include <cstring>
#include <stdexcept>

class S {

public:
	S();
	S( char character );
	S( const char* buffer );
	S( const S& other );
	~S();

	S& operator=( const S& other );
	S operator+( const S& other ) const;
	S& operator+=( const S& other );

	std::size_t length() const;
	const char& operator[]( std::size_t index ) const;
	const char* str() const;

private:
	char* buffer;
	std::size_t bufferSize;
};

//----------------------------------------------------------------------------------------------------------------------

// Нужен символ '\0', чтобы было совместимо с C-строками.
// Скажем, должен работать следующий код:
// S a( "Hello!" );
// S b( a.str() );
// Более того, удобно иметь bufferSize хотя бы 1 всегда, так как нередко придётся
// вычитать 1, а тип беззнаковый.
S::S() :
	bufferSize( 1 )
{
	buffer = new char[1];
	buffer[0] = '\0';
}

S::S( char character ) :
	bufferSize( 2 )
{
	buffer = new char[2];
	buffer[0] = character;
	buffer[1] = '\0';
}

S::S( const char* string ) :
	bufferSize( strlen( string ) + 1 )
{
	buffer = new char[bufferSize];
	strncpy( buffer, string, strlen( string ) );
}

S::S( const S& other )
{
	//if( buffer != 0 ) {
	//	*this = other;
	//} else {
		bufferSize = other.bufferSize;
		buffer = new char[bufferSize];
		strncpy( buffer, other.buffer, other.length() );
	//}
}

S::~S()
{
	delete[] buffer;
}

S& S::operator=( const S& other )
{
	if( other.buffer == buffer ) {
		return *this;
	}
	delete[] buffer;
	bufferSize = other.bufferSize;
	buffer = new char[bufferSize];
	strncpy( buffer, other.buffer, other.length() );
	return *this;
}

S S::operator+( const S& other ) const
{
	S tempObject = *this;
	tempObject += other;
	return tempObject; // возвращает сам объект, а не адрес - т.к. он новый
}

S& S::operator+=( const S& other )
{
	std::size_t newBufferSize = bufferSize + other.length();
	char* newBuffer = new char[newBufferSize];
	strncpy( newBuffer, buffer, length() );
	strncpy( newBuffer + length(), other.str(), other.length() );
	delete[] buffer;
	buffer = new char[newBufferSize];
	bufferSize = newBufferSize;
	strncpy( buffer, newBuffer, static_cast<std::size_t>( newBufferSize - 1 ) );
	delete[] newBuffer;
	return *this;
}

std::size_t S::length() const
{
	return static_cast<std::size_t>( bufferSize - 1 );
}

const char& S::operator[]( std::size_t index ) const
{
	if( index >= static_cast<std::size_t>( bufferSize - 1 ) ) {
		throw std::range_error( "range error" );
	}
	return buffer[index];
}

const char* S::str() const
{
	return buffer;
}

std::ostream& operator<<( std::ostream& stream, const S& string )
{
	stream.write( string.str(), string.length() );
	return stream;
}


