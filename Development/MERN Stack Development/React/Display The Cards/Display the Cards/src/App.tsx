import { useEffect, useState } from 'react'

function App() {

  const [cards, setCards] = useState([]);
  const url = `https://jsonplaceholder.typicode.com/posts`;

  async function fetchData()
  {
    const response: any = await fetch(url);
    const dataObject: any = await response.json();
    setCards(dataObject);
  }
  useEffect(() => {
    fetchData();
  }, []);

  return (
    <>
      <div className="cardContainer p-4 flex flex-col items-center">
        {cards.map((card: any) => {
          return <div className="card border-2 border-amber-600 m-2 p-4 rounded-2xl bg-amber-500 text-amber-50 size-80">
            <h1 className='font-bold text-2xl my-2'>{card.title}</h1>
            <p>{card.body}</p>
          </div>
        })}
      </div>
    </>
  )
}

export default App
