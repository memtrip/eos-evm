
import com.memtrip.eos.http.rpc.Api
import com.memtrip.evm.eos.Config
import com.memtrip.evm.eos.SetupTransactions
import com.memtrip.evm.eos.state.GetAccountState
import com.memtrip.evm.eos.actions.execute.ExecuteAction
import okhttp3.OkHttpClient
import okhttp3.logging.HttpLoggingInterceptor
import java.util.concurrent.TimeUnit

//
// 11.05.2020
// Auto generated based off the Ethereum tests found here:
// https://github.com/ethereum/tests/blob/develop/VMTests/
//
class vmBlockInfoTest {
    private val okHttpClient = OkHttpClient.Builder()
        .addInterceptor(HttpLoggingInterceptor().setLevel(HttpLoggingInterceptor.Level.BODY))
        .connectTimeout(10, TimeUnit.SECONDS)
        .readTimeout(10, TimeUnit.SECONDS)
        .writeTimeout(10, TimeUnit.SECONDS)
        .build()

    private val chainApi = Api(Config.CHAIN_API_BASE_URL, okHttpClient).chain

    private val setupTransactions = SetupTransactions(chainApi)

    private val executeAction = ExecuteAction(chainApi)

    private val getAccountState = GetAccountState(chainApi)
}
