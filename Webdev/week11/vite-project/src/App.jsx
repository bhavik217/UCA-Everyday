// import { aHeader as AHeader } from "./aHeader";
// import ProductList from "./components/productList";

// export function App() {
//   return (
//     <>
//       <header>
//         <AHeader></AHeader>
//       </header>
//       <main><ProductList l1 = "l1"></ProductList></main>
//       <footer></footer>
//     </>
//   );
// }

import { aHeader as AHeader } from "./aHeader";
import ProductList from "./components/productList";
import { createBrowserRouter, RouterProvider } from "react-router-dom";
import { Signup } from "./components/signup/Signup";

export function App() {
    return (
        <>
            <header>
                <AHeader></AHeader>
            </header>
            {/* <main><ProductList l1 = "l1"></ProductList></main> */}
            <main>
                <RouterProvider router={router}></RouterProvider>
            </main>
            <footer></footer>
        </>
    );
}