import { Router } from "react-router-dom"

const router = createBrowserRouter([
    {
        path: "/",
        element: <ProductList></ProductList>
    },
    {
        path: "signup",
        element: <Signup></Signup>
    }
])