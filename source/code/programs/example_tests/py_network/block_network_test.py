import socket
import unittest

class IsolatedNetworkTest(unittest.TestCase):
    def test_listen(self):
        # Use a fixed port
        serversocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        serversocket.bind((socket.gethostname(), 9999))

        # Wait for 5 seconds with the port open
        serversocket.settimeout(5)
        serversocket.listen(5)

        with self.assertRaises(socket.timeout):
            serversocket.accept()

if __name__ == "__main__":
    unittest.main()